#ifndef _MClothSystem
#define _MClothSystem
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
// ****************************************************************************
//
// CLASS:    MClothSystem
//
// ****************************************************************************
//
// CLASS DESCRIPTION (MClothSystem)
//
//   Interface for cloth solver system. 
//
// ****************************************************************************

#if defined __cplusplus

// ****************************************************************************

// INCLUDED HEADER FILES
#include <maya/MVector.h>

#include <maya/MClothTypes.h> 

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

// ****************************************************************************

// DECLARATIONS

class MIntArray;
class MDoubleArray;
class MPointArray;
class MVectorArray;
class MPoint;
class MVector;
class MClothMaterial;
class MClothPolyhedron;
class MIntArray;
class MObject; 

class MClothTriangle;
class MClothParticle;
class MClothConstraint;
class MClothConstraintCmd;
class MClothForce;

struct MSeamInfo {
	int		particleIndex,
			triangleIndex;
	double	u,
			v;
};

// ****************************************************************************

// CLASS DECLARATION (MClothSystem)

/// Interface for cloth solver system.
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class MAYACLOTH_EXPORT MClothSystem
{
public: 
	///
	MClothSystem(); 
	///
	virtual	~MClothSystem(); 

	// interface method for adding/removing cloth mesh inside solver.
	///
	virtual MStatus		addCloth( MClothHandle handle, 
								  int nParticles,
								  int nTriangles,
								  int vertexList[][3], 
								  const MDoubleArray& uArray,
								  const MDoubleArray& vArray,
								  MSeamInfo *seam = NULL,
								  int nSeam = 0 ) = 0;
	///
	virtual MStatus		addCloth( MClothHandle handle,
								  int nParticles,
								  int nTriangles,
								  int vertexList[][3],
								  const MPointArray& particles,
								  MSeamInfo *seam = NULL, 
								  int nSeam = 0, 
								  const MPointArray *uvs=NULL) = 0;

	///
	virtual MStatus		removeCloth( MClothHandle handle ) = 0;

	// Get the new material instance. Cloth Plugin maintains list of materials
	// assigned.
	///
	virtual MClothMaterial* getNewMaterialInstance( MStatus *ReturnStatus = NULL ) = 0;

	///
	virtual void		setMaterial( MClothHandle handle, 
									 MClothMaterial *material,
									 int triIndex = 0,
									 MStatus* ReturnStatus = NULL ) = 0;
	///
	virtual void		updateMaterial( MClothHandle handle,
										MStatus* ReturnStatus = NULL ) = 0;

	///
	virtual unsigned    numTriangles( MClothHandle handle,
									  MStatus* ReturnStatus = NULL ) const = 0;
	///
	virtual unsigned	numParticles( MClothHandle handle,
									  MStatus* ReturnStatus = NULL ) const = 0;
	///
	virtual MClothParticle*  getParticle( MClothHandle handle,
										  unsigned index,
										  MStatus* ReturnStatus = NULL ) const = 0;
	///
	virtual MClothTriangle*  getTriangle( MClothHandle handle,
										  unsigned index,
										  MStatus* ReturnStatus = NULL ) const = 0;

	// If Index == -1 then it means Select All vertices's
	// else return the neighbors for given index.
	///
	virtual MStatus		getClothNeighbours( MClothHandle handle, 
											MIntArray& result,
											int index = -1 ) = 0;
	///
	virtual MStatus		getClothContacts( MClothHandle handle,
										  MIntArray& result,
										  int index = -1 ) = 0;
	///
	virtual MStatus		getClothForces( MClothHandle handle,
										MDoubleArray& result,
										int index = -1 ) = 0;

	///
	virtual MStatus		getStress( MClothHandle handle,
								   MDoubleArray& result,
								   int index = -1 ) = 0;

	// Scale the stress, exaggerating those closer to 1, but keeping
	// them in the 0..1 range.
	///
	virtual MStatus		getStress_scaled( MClothHandle handle,
										  double stress[] ) = 0;

	///
	virtual double		getBendingForce( MClothHandle handle,
										 int triangleNo,
										 int edgeNo,
										 MStatus* ReturnStatus = NULL ) = 0;
	///
	virtual void		setBendingForce( MClothHandle handle,
										int triangleNo,
										int edgeNo,
										double theta,
										double weight,
										MStatus* ReturnStatus = NULL ) = 0;
	///
	virtual void		setBendResistance( MClothHandle handle,
										int triangleNo,
										int edgeNo,
						                                double resistance,
										MStatus* ReturnStatus = NULL ) = 0;

	// interface methods to get properties of individual cloth objects inside solver.
	///
	virtual void		getPosition( MClothHandle handle,
									 MPointArray& position,
									 MStatus* ReturnStatus = NULL ) const = 0;
	///
	virtual void		setPosition( MClothHandle handle,
									 MPointArray& position,
									 MStatus* ReturnStatus = NULL ) = 0;
	///
	virtual void		getVelocity( MClothHandle handle,
									 MVectorArray& velocity,
									 MStatus* ReturnStatus = NULL ) const = 0;
	///
	virtual void		setVelocity( MClothHandle handle,
									 MVectorArray& velocity,
									 MStatus* ReturnStatus = NULL ) = 0;

	// interface methods for complete solver system.
	///
	virtual unsigned    numTriangles( MStatus* ReturnStatus = NULL ) const = 0;
	///
	virtual unsigned	numParticles( MStatus* ReturnStatus = NULL ) const = 0;

	// Simulation related methods...
	///
	virtual bool		preSolve(); 

	/// 
	virtual bool		postSolve(); 
	
	///
	virtual void		interpolate( double frameTime,
									 MStatus* ReturnStatus = NULL ) = 0;
	///
	virtual double		step_forward( double stepSize,
									  MStatus* ReturnStatus = NULL ) = 0;
	///
	virtual void		restart( double frameTime,
								 MStatus* ReturnStatus = NULL) = 0;
	///
	virtual double		frameSize( MStatus* ReturnStatus = NULL ) const = 0;
	///
	virtual void		setFrameSize( const double frameSize,
									  MStatus* ReturnStatus = NULL ) = 0;
	///
	virtual double		currentTime( MStatus* ReturnStatus = NULL ) const = 0;
	///
	virtual void		setCurrentTime( const double currTime,
									    MStatus* ReturnStatus = NULL ) = 0;
	///
	virtual double		lastTime( MStatus* ReturnStatus = NULL ) const = 0;
	///
	virtual double		stepSize( MStatus* ReturnStatus = NULL ) const = 0;

	// Constraint related methods...
	///
	virtual MClothConstraint* lockParticle( MClothParticle *particle,
											MClothPolyhedron *poly,
											int triIndex,
											MStatus* ReturnStatus = NULL ) = 0;
	///
	virtual void		 unlockParticle( MClothParticle *particle,
										 MStatus* ReturnStatus = NULL ) = 0;
	///
	virtual void		 unlockParticle( MClothConstraint *constaint,
										 MStatus* ReturnStatus = NULL ) = 0;
	///
	virtual void		 addCommand( MClothConstraintCmd *command,
									 MStatus* ReturnStatus = NULL ) = 0;
	///
	virtual void		 removeCommand( MClothConstraintCmd *command,
										MStatus* ReturnStatus = NULL ) = 0;
	///
	virtual MClothForce* addSpring( MClothParticle* particle1,
									MClothParticle* particle2,
									double ks,
									double kd,
									MStatus* ReturnStatus = NULL) = 0;
	///
	virtual MClothForce* addSpring( MClothParticle* particle1,
									MClothTriangle *clothTriangle,
									MPoint bary,
									double ks,
									double kd,
									MStatus* ReturnStatus = NULL) = 0;
	///
	virtual void		 removeSpring( MClothForce *springForce,
									   MStatus* ReturnStatus = NULL) = 0;

	// Some rigid body related information..
	///
	virtual MClothPolyhedron* createRigidbody( int numVertices,
											   int indices[][3], 
											   int numTriangles,
											   double triDepthMap[],
											   double triCollisionOffsetMap[],
											   char *name = NULL,
											   unsigned numRampSamples = 0,
											   float* offsetVelIncrement = NULL,
											   float* depthVelIncrement = NULL,
												bool collisionEnable = true,
											   MStatus* ReturnStatus = NULL ) = 0;
	///
	virtual MStatus		addRigidbody( MClothPolyhedron* body ) = 0;
	///
	virtual MStatus		removeRigidbody( MClothPolyhedron* body ) = 0;

	///
	virtual void		setVelocity_CutOff( const double min,
											const double max,
											const double damping,
											MStatus* ReturnStatus = NULL ) = 0;
	///
	virtual void		setPinchMethod( const short method,
										MStatus* ReturnStatus = NULL ) = 0;
	///
	virtual void		setIgnoreCollisions( const bool ignore,
											 MStatus* ReturnStatus = NULL ) = 0;

	// Number of rows of neighbor particles to dampen
	///
	virtual int			getRecoilWidth( MStatus* ReturnStatus = NULL ) const = 0;
	///
	virtual void		setRecoilWidth( int width,
										MStatus* ReturnStatus = NULL ) = 0;
	
	// Time length until mass is restored after collision
	///
	virtual int			getRecoilDuration( MStatus* ReturnStatus = NULL ) const = 0;
	///
	virtual void		setRecoilDuration( int duration,
										   MStatus* ReturnStatus = NULL ) = 0;
	
	// These are generic utilities.
	///
	virtual int findClosestPolyhedron( MClothPolyhedron *spAry[],
									   int spCount,
									   MPoint x,
									   double maxd,
									   MStatus* ReturnStatus = NULL ) = 0;
	///
	virtual int findTriangle( MClothPolyhedron *sp,
							  MPoint x,
							  double maxd,
							  double *closestDist = NULL,
							  MStatus* ReturnStatus = NULL ) = 0;
	///
	virtual int findClothTriangle( MClothHandle handle,
								   MPoint x,
								   MPoint &barycentric,
								   MStatus* ReturnStatus = NULL ) = 0;
	///
	virtual int findClothTriangle( MClothHandle handle,
								   MPoint x,
								   const MIntArray& excludedTriangles,
								   MPoint &barycentric,
								   MStatus* ReturnStatus = NULL ) = 0;
	///
	virtual int findClothTriangle( const MPointArray& clothPositions,
								   MPoint x,
								   MPoint &barycentric,
								   MStatus* ReturnStatus = NULL ) = 0;
	///
	virtual MStatus findNeighborTriangles( MClothHandle handle,
										int vertexIndex,
										int neighborhood,
										MIntArray& neighborTriangles ) = 0;

	///
	MObject			solverNode(); 
	
	virtual void 	initRecoilState() = 0;
	virtual void 	setRecoilParams(float, unsigned char, unsigned char, float) = 0;
	virtual float	recoilScale() = 0;
	virtual void	tagRecoilParticle(MClothParticle *,
					  unsigned char width,
					  unsigned char duration,
					  float         scale,
					  float         priority) = 0; 


public:
	// Internal use for MayaCloth plugin.
	///
	void				setUserdata( void* userPtr );
	///
	void*				getUserdata();

protected:
	// No protected members

private:
	void* fUserData;
}; 

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// ****************************************************************************
#endif /* __cplusplus */
#endif /* _MClothSystem */
