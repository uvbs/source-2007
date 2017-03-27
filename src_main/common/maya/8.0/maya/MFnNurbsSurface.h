#ifndef _MFnNurbsSurface
#define _MFnNurbsSurface
//
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
//
// CLASS:    MFnNurbsSurface
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnNurbsSurface)
//
// This is the function set for NURBS (non-uniform ration B-spline) surfaces.
//
// The U and V knot vectors for NURBS surfaces are of size
// {\bf (spansInU + 2*degreeInU -1)} and {\bf (spansInV + 2*degreeInV -1)}. 
// Note: spans = numCVs - degree.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MFnDagNode.h>
#include <maya/MPoint.h>
#include <maya/MVector.h>
#include <maya/MObject.h>
#include <maya/MTesselationParams.h>
#include <maya/MObjectArray.h>

// *****************************************************************************

// DECLARATIONS

class MPointArray;
class MDoubleArray; 
class MFloatArray;
class MIntArray;
class MPoint;
class MVector;
class MDagPath;
class MPtrBase;
class MDGModifier;
class MSelectionList;
class MTrimBoundaryArray;
class TnurbsCurvePtrArray;
struct ag_curve;

#define kMFnNurbsEpsilon  1.0e-3

// *****************************************************************************

class MFnNurbsSurface;
typedef MStatus (MFnNurbsSurface::*setKnotsFnPtr)( unsigned int, double ); 
typedef int (MFnNurbsSurface::*numKnotsFnPtr)( MStatus* ) const; 
                                                   

// CLASS DECLARATION (MFnNurbsSurface)

/// NURBS surface function set
/**

*/

#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MFnNurbsSurface : public MFnDagNode 
{
	declareDagMFn(MFnNurbsSurface, MFnDagNode);

public:
    ///
	enum Form {
        ///
		kInvalid =0,
        ///
		kOpen,
        ///
		kClosed,
        ///
		kPeriodic,
        ///
		kLast
	};
    ///
	MObject 	create(	const MPointArray &controlVertices,
						const MDoubleArray &uKnotSequences,
						const MDoubleArray &vKnotSequences,
						unsigned int degreeInU,
						unsigned int degreeInV,
						Form formU,
						Form formV,
						bool createRational,
						MObject parentOrOwner = MObject::kNullObj,
						MStatus* ReturnStatus = NULL );
	///
	MObject     copy( const MObject &source,
					  MObject parentOrOwner = MObject::kNullObj,
					  MStatus* ReturnStatus = NULL );
    ///
	MObject 	cv( unsigned int indexU, unsigned int indexV, 
						MStatus * ReturnStatus = NULL );
    ///
	MObject		cvsInU( unsigned int startIndex,
					    unsigned int endIndex,
						unsigned int rowIndex, 
						MStatus * ReturnStatus = NULL );
    ///
	MObject		cvsInV( unsigned int startIndex,
						unsigned int endIndex,
						unsigned int rowIndex, 
						MStatus * ReturnStatus = NULL ); 
    ///
	MStatus		getCVs( MPointArray& array,
						MSpace::Space space = MSpace::kObject ) const;
	///
	MStatus		setCVs( const MPointArray& array,
						MSpace::Space space = MSpace::kObject );
	///
	MStatus		getCV( unsigned int indexU, unsigned int indexV, MPoint& pnt,
						MSpace::Space space = MSpace::kObject ) const;
	///
	MStatus		setCV( unsigned int indexU, unsigned int indexV, MPoint& pnt,
						MSpace::Space space = MSpace::kObject ) const;
	///
	Form		formInU( MStatus * ReturnStatus = NULL ) const;
    ///
	Form		formInV( MStatus * ReturnStatus = NULL ) const;
    ///
	bool		isBezier( MStatus * ReturnStatus = NULL ) const;
    ///
	bool		isUniform( MStatus * ReturnStatus = NULL ) const;
    ///
	bool		isKnotU( double param, MStatus * ReturnStatus = NULL ) const;
    ///
	bool		isKnotV( double param, MStatus * ReturnStatus = NULL ) const;
    ///
	bool		isParamOnSurface( double paramU, double paramV, 
						MStatus * ReturnStatus = NULL ) const;
    ///
	MStatus		getKnotDomain( double &startU, double &endU, double &startV, 
						double &endV ) const; 
    ///
	int			degreeU( MStatus * ReturnStatus = NULL ) const;
    ///
	int			degreeV( MStatus * ReturnStatus = NULL ) const;
    ///
	int			numSpansInU( MStatus * ReturnStatus = NULL ) const;
    ///
	int			numSpansInV( MStatus * ReturnStatus = NULL ) const;
    ///
	int			numNonZeroSpansInU( MStatus * ReturnStatus = NULL ) const;
    ///
	int			numNonZeroSpansInV( MStatus * ReturnStatus = NULL ) const;
    ///
	int			numCVsInU( MStatus * ReturnStatus = NULL ) const;
    ///
	int			numCVsInV( MStatus * ReturnStatus = NULL ) const;
    ///
	int			numKnotsInU( MStatus * ReturnStatus = NULL ) const;
    ///
	int			numKnotsInV( MStatus * ReturnStatus = NULL ) const;
    ///
	MStatus		getKnotsInU( MDoubleArray &array ) const;
    ///
	MStatus		getKnotsInV( MDoubleArray &array ) const;  
    ///
	MStatus		setKnotsInU( const MDoubleArray &array, unsigned int startIndex,
						unsigned int endIndex );
    ///
	MStatus		setKnotsInV( const MDoubleArray &array, unsigned int startIndex,
						unsigned int endIndex );
    ///
	double		knotInU( unsigned int index, MStatus * ReturnStatus = NULL ) const;
    ///
	double		knotInV( unsigned int index, MStatus * ReturnStatus = NULL ) const;
    ///
	MStatus		setKnotInU( unsigned int index, double param );
    ///
	MStatus		setKnotInV( unsigned int index, double param );
    ///
	MStatus		removeKnotInU( double atThisParam, bool removeAll = false );
    ///
	MStatus		removeKnotInV( double atThisParam,  bool removeAll = false );
    ///
	MStatus		removeOneKnotInU( double atThisParam );
    ///
	MStatus		removeOneKnotInV( double atThisParam );
    ///
    MVector		normal( double paramInU, double paramInV, 
						MSpace::Space space = MSpace::kObject,
						MStatus * ReturnStatus = NULL ) const;
    ///
    MStatus		getTangents( double paramInU, double paramInV, 
						MVector &vectorInU, MVector &vectorInV,
						MSpace::Space space = MSpace::kObject) const; 
    ///
    MStatus		getDerivativesAtParm( double paramInU, double paramInV, 
									  MPoint &pos, MVector &dU, MVector &dV, 
									  MSpace::Space space,
									  MVector * dUU = NULL, 
									  MVector * dVV = NULL, 
									  MVector * dUV = NULL) const; 
    ///
	bool		isFoldedOnBispan() const;
    ///
	double		area( double tolerance = kMFnNurbsEpsilon, 
						MStatus * ReturnStatus = NULL ) const;

    ///
	double		area( MSpace::Space space,
						double tolerance = kMFnNurbsEpsilon,						 
						MStatus * ReturnStatus = NULL ) const;

    ///
	MPoint		closestPoint( const MPoint &toThisPoint, 
						double * paramU = NULL,
						double * paramV = NULL,
						bool ignoreTrimBoundaries = false,
						double tolerance = kMFnNurbsEpsilon, 
						MSpace::Space space = MSpace::kObject,
						MStatus * ReturnStatus = NULL ) const;
    ///
	MPoint		closestPoint( const MPoint &toThisPoint, 
						bool paramAsStart = true,
						double * paramU = NULL,
						double * paramV = NULL,
						bool ignoreTrimBoundaries = false,
						double tolerance = kMFnNurbsEpsilon, 
						MSpace::Space space = MSpace::kObject,
						MStatus * ReturnStatus = NULL ) const;
    ///
	bool		isPointOnSurface( const MPoint &point, 
						double tolerance = kMFnNurbsEpsilon, 
						MSpace::Space space = MSpace::kObject,
						MStatus * ReturnStatus = NULL ) const;
    /// OBSOLETE
	MStatus		getParamAtPoint( const MPoint & atThisPoint,
						double &paramU, double &paramV,
						MSpace::Space space = MSpace::kObject) const;
    ///
	MStatus		getParamAtPoint( const MPoint & atThisPoint,
						double &paramU, double &paramV,
						bool ignoreTrimBoundaries,
						MSpace::Space space = MSpace::kObject,
						double tolerance = kMFnNurbsEpsilon) const;
    ///
	MStatus		getPointAtParam( double paramU, double paramV, MPoint &point,
						MSpace::Space space = MSpace::kObject) const;
    ///
	double		distanceToPoint( const MPoint &pt, 
						MSpace::Space space = MSpace::kObject,
						MStatus * ReturnStatus = NULL ) const;
	///
	MObject		tesselate( MTesselationParams & parms =
						MTesselationParams::fsDefaultTesselationParams,
                        MObject parentOrOwner = MObject::kNullObj,
						MStatus * ReturnStatus = NULL );

	///
	bool		intersect( const MPoint &rayStartingPoint,
						const MVector &alongThisDirection,
						double &u, double &v,
						MPoint &intersectionData,
						double tolerance = kMFnNurbsEpsilon,
						MSpace::Space space = MSpace::kObject,
						bool calculateDistance = false,
						double * distance = NULL,
						bool calculateExactHit = false,
						bool* wasExactHit = NULL,
						MStatus* ReturnStatus = NULL ) const;
	///
	bool		intersect( const MPoint &rayStartingPoint,
						const MVector &alongThisDirection,
						MDoubleArray &u, MDoubleArray &v,
						MPointArray &intersectionData,
						double tolerance = kMFnNurbsEpsilon,
						MSpace::Space space = MSpace::kObject,
						bool calculateDistance = false,
						MDoubleArray * distances = NULL,
						bool calculateExactHit = false,
						bool* wasExactHit = NULL,
						MStatus* ReturnStatus = NULL ) const;

    ///
	bool		hasHistoryOnCreate( MStatus * ReturnStatus = NULL );
    ///
	MStatus		updateSurface();


    ///
	enum BoundaryType {
        ///
		kInvalidBoundary=0,
        ///
		kOuter,
        ///
		kInner,
        ///
		kSegment,
        ///
		kClosedSegment
	};
	///
	bool		isTrimmedSurface( MStatus * ReturnStatus = NULL );
	///
	unsigned int	numRegions( MStatus * ReturnStatus = NULL );
	///
	bool		isFlipNorm( unsigned int region, MStatus * ReturnStatus = NULL );
	///
	unsigned int	numBoundaries( unsigned int region, MStatus * ReturnStatus = NULL);
	///
	BoundaryType boundaryType( unsigned int region, unsigned int boundary,
						MStatus * ReturnStatus = NULL );
	///
	unsigned int     numEdges( unsigned int region, unsigned int boundary,
    					MStatus * ReturnStatus = NULL );
	///
	MObjectArray edge( unsigned int region, unsigned int boundary, unsigned int edge,
				 	 	bool paramEdge = false,
						MStatus * ReturnStatus = NULL );

	///
	bool        isPointInTrimmedRegion( double u, double v,
						MStatus * ReturnStatus = NULL );

	///
	MStatus		getTrimBoundaries(MTrimBoundaryArray& result,
    							  unsigned int region,
    							  bool paramEdge = true);
	///
	MStatus		trimWithBoundaries(const MTrimBoundaryArray& mBoundaries,
    							   bool  flipNormal = false,
    							   double e_tol = 1e-3,
    							   double pe_tol = 1e-5);
	///
	MStatus 	projectCurve( MDagPath& curve, MVector * direction = NULL,
				 		bool constructionHistory = false );
	///
	MStatus		trim( MDoubleArray& locatorU, MDoubleArray& locatorV,
						bool constructionHistory = false );

	// Support methods needed to do patch level explicit uv assignment and
	// editing.

	///
	unsigned int     numPatches( MStatus * ReturnStatus = NULL ) const;
	///
	unsigned int     numPatchesInU( MStatus * ReturnStatus = NULL ) const;
	///
	unsigned int     numPatchesInV( MStatus * ReturnStatus = NULL ) const;
	
	// Explicit uv related methods..
	//
	///
	int			numUVs( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus 	setUVs( const MFloatArray& uArray, const MFloatArray& vArray);
	///
	MStatus 	getUVs( MFloatArray& uArray, MFloatArray& vArray ) const;
	///
	MStatus		setUV( int uvId, float u, float v );
	///
	MStatus		getUV( int uvId, float & u, float & v ) const;
	///
	MStatus 	getPatchUV( int patchId, int cornerIndex, 
									float & u, float & v ) const;
	///
	MStatus 	getPatchUVs( int patchId, MFloatArray& uArray,
												MFloatArray& vArray) const;
	///
	MStatus 	getPatchUVid( int patchId, int cornerIndex, int &uvId ) const;
	///
	MStatus 	assignUV( int patchId, int cornerIndex, int uvId );
	///
	MStatus		assignUVs( const MIntArray& uvCounts, const MIntArray& uvIds );
	///
	MStatus		clearUVs( );
	///
	MStatus		getAssignedUVs( MIntArray& uvCounts, MIntArray& uvIds) const;

	/// OBSOLETE
	MObject		tesselate( MTesselationParams & parms,
						MStatus * ReturnStatus );


protected: 
	virtual bool objectChanged( MFn::Type, MStatus * );
	bool		getUVSetIndex( const MString * uvSetName,
								int & uvSet) const;
	bool		curveToMObjects(ag_curve*       crv,
    							MObjectArray&   curveArray,
    							MStatus         *ReturnStatus);
	bool		trimWithBoundariesInHistory(
								const TnurbsCurvePtrArray& boundaries,
    							bool  flipnorm,
    							double   e_tol,
    							double   pe_tol,
    							MStatus  *status);
private:
    
    // function used for both setKnotsInU() and setKnotsInV()
    
    MStatus setKnotsUsingFn( const MDoubleArray& array, unsigned int startIndex,
					 unsigned int endIndex, numKnotsFnPtr numKnotFn,
					 setKnotsFnPtr setKnotFn );

	inline void * updateGeomPtr() const;
	inline void * updateConstGeomPtr() const;

};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MFnNurbsSurface */
