#ifndef _MClothControl
#define _MClothControl
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
// CLASS:    MClothControl
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MClothControl)
//
//  This class provides access to various cloth data. This includes UVs per
//	per cloth, UVs per panel, stitcher node of a cloth, solver node of a cloth,
//	face membership of a panel, etc.
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

#include <maya/MClothTypes.h> 

class MObject;
class MIntArray;
class MDoubleArray;
class MClothPolyhedron;
class MClothSystem; 
class MDagPath;

// *****************************************************************************

// CLASS DECLARATION (MClothControl)

/// Access to cloth data
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class MAYACLOTH_EXPORT MClothControl
{
public:
	///
								MClothControl();
	///
	virtual						~MClothControl();
	///
	static MStatus				getUVs( const MString& cloth,
										const MString& panel,
										MDoubleArray& uvs );
	///
	static int					panelId( const MString& panel,
										 MStatus* ReturnStatus = NULL );
	///
	static MStatus				panelFaces( const MString& panel,
											MIntArray& faceIds );
	///
	static MObject				solverNode( const MString& cloth,
											MStatus* ReturnStatus = NULL );
	
	///
	static MObject				currentSolver(); 
	
	///
	static void					getClothSystem( const MObject &solver,
												MClothSystem*& system, 
												MStatus *ReturnStatus = NULL );
												
	///
	static MObject				stitcherNode( const MString& cloth,
											  MStatus* ReturnStatus = NULL );

	///
	static bool					isClothMesh( MDagPath &path, MObject &solver,
											 int &index ); 

	/// 
	static bool					getClothFromSolver( const MObject &solver, 
													int plugIndex,
													MObject &cloth );

	///
	static bool					isSolverCloth( const MDagPath &cloth, 
											   const MString &solverName,
											   MClothSystem*& system,
											   MClothHandle& handle );

	///
	static double				getPrecedingFrame(	MClothSystem &system,
													double currentTime,
													double& precedingTime,
													MStatus* ReturnStatus = NULL);
	///
	static double				getSucceedingFrame( MClothSystem &system,
													double currentTime, 
													double& succeedingTime,
													MStatus* ReturnStatus = NULL);
	///
	static void					loadFrame( MClothPolyhedron &rigidBody,
										   double frame, 
										   int cacheNumber,
										   MStatus* ReturnStatus = NULL);
	///
	static double				dgTimeGivenClothFrame( MClothPolyhedron &rigidBody,
													   double frame,
													   MStatus* ReturnStatus = NULL);
	///
	static int					pinch(	MClothSystem &system, 
										MClothPolyhedron *poly1, 
										unsigned triIndex1, 
										MClothPolyhedron *poly2, 
										unsigned triIndex2,
										MStatus* ReturnStatus = NULL);
	///
	static void					externalForces( MClothSystem &system,
												MStatus* ReturnStatus = NULL);
	///
	static bool					solveCB( MClothSystem &system,
										 double cutoff, 
										 double cur, 
										 int istep);
	///
	static bool					collisionCB( MClothSystem &system,
											 int ipass,
											 double maxp);
	///
	static bool					stepCB( MClothSystem &system,
										double h);
	///
	static bool					interruptCheckCB( MClothSystem &system );

protected:
// No protected members

private:
// No private members
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MClothControl */
