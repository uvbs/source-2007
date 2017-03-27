#ifndef _MClothPolyhedron
#define _MClothPolyhedron
//-
// ==========================================================================
// Copyright (C) 1995 - 2006 Autodesk, Inc., and/or its licensors.  All 
// rights reserved.
// 
// The coded instructions, statements, computer programs, and/or related 
// material (collectively the "Data") in these files contain unpublished 
// information proprietary to Autodesk, Inc. ("Autodesk") and/or its 
// licensors,  which is protected by U.S. and Canadian federal copyright law 
// and by international treaties.
// 
// The Data may not be disclosed or distributed to third parties or be 
// copied or duplicated, in whole or in part, without the prior written 
// consent of Autodesk.
// 
// The copyright notices in the Software and this entire statement, 
// including the above license grant, this restriction and the following 
// disclaimer, must be included in all copies of the Software, in whole 
// or in part, and all derivative works of the Software, unless such copies 
// or derivative works are solely in the form of machine-executable object 
// code generated by a source language processor.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND. 
// AUTODESK DOES NOT MAKE AND HEREBY DISCLAIMS ANY EXPRESS OR IMPLIED 
// WARRANTIES INCLUDING, BUT NOT LIMITED TO, THE WARRANTIES OF 
// NON-INFRINGEMENT, MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE, 
// OR ARISING FROM A COURSE OF DEALING, USAGE, OR TRADE PRACTICE. IN NO 
// EVENT WILL AUTODESK AND/OR ITS LICENSORS BE LIABLE FOR ANY LOST 
// REVENUES, DATA, OR PROFITS, OR SPECIAL, DIRECT, INDIRECT, OR 
// CONSEQUENTIAL DAMAGES, EVEN IF AUTODESK AND/OR ITS LICENSORS HAS 
// BEEN ADVISED OF THE POSSIBILITY OR PROBABILITY OF SUCH DAMAGES. 
// ==========================================================================
//+
// *****************************************************************************
//
// CLASS:    MClothPolyhedron
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MClothPolyhedron)
//
//   Interface for cloth solver collision rigid body. 
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


// MayaCloth Export
#ifdef _WIN32
#	ifndef MAYACLOTH_EXPORT
#		ifdef MAYACLOTH_DLL 
#			define MAYACLOTH_EXPORT _declspec( dllexport )
#		else
#			define MAYACLOTH_EXPORT _declspec( dllimport )
#		endif // MAYACLOTH_DLL
#	endif // MAYACLOTH_EXPORT
#else
#	ifndef MAYACLOTH_EXPORT
#		define MAYACLOTH_EXPORT
#	endif
#endif // _WIN32

// *****************************************************************************

// DECLARATIONS
class MPoint;
class MPointArray;
class MObject;
class MIntArray; 

// *****************************************************************************

// CLASS DECLARATION (MClothPolyhedron)

/// Interface for cloth solver collision rigid body.
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class MAYACLOTH_EXPORT MClothPolyhedron
{
public:
	///
	MClothPolyhedron();
	///
	virtual ~MClothPolyhedron();

	///
	virtual MStatus create( int nVertices,
							int indices[][3], 
							int nTriangles,
							double triDepthMap[],
							double triCollisionOffsetMap[],
							char *name = NULL,
							unsigned numRampSamples = 0, 
							float* offsetVelMultiplier = NULL,
							float* depthVelMultiplier = NULL,
							double dynFrictionMultiplier = 1.0,
							double staticFrictionMultiplier = 1.0,
							bool collisionEnable = true ) = 0;

	///
	virtual unsigned numVertices( MStatus* ReturnStatus = NULL ) const = 0;
	///
	virtual unsigned numTriangles( MStatus* ReturnStatus = NULL ) const = 0;

	///
	virtual MStatus setPosition( const MPointArray& postions ) = 0;
	///
	virtual MStatus setPosition( int index,
							  const MPoint& position,
							  int cacheNumber = 0 ) = 0;
	///
	virtual MStatus getPosition( MPointArray& postions ) = 0;

	///
	virtual MStatus updateNormals( bool init = false ) = 0;
	///
	virtual MStatus updateFromMesh( double currTime,
									double scale,
									const MObject& newMesh ) = 0;
	///
	virtual MStatus updateVelocityMultiplier( unsigned numRampSamples,
											 float offsetVelMultiplier[],
											 float depthVelMultiplier[] ) = 0;

	///
	virtual	void updateDynFrictionMultiplier( double val ) = 0;
	///
	virtual void updateStaticFrictionMultiplier( double val ) = 0;
	///
	virtual void disableCollisions( const MIntArray &faces ); 
	
	virtual void setCollisionEnable( bool collision ) = 0; 
	///
	virtual void resetDisabledCollisions();

public:
	// Internal use for CpClothSolver plugin.
	///
	void  setUserdata( void* userPtr );
	///
	void* getUserdata();

protected:
	// No protected members

private:
	void* fUserData;
};

typedef MClothPolyhedron * MClothPolyhedronPtr;

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MClothPolyhedron */

