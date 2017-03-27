#ifndef _MItMeshFaceVertex
#define _MItMeshFaceVertex
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
// CLASS:    MItMeshFaceVertex
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MItMeshFaceVertex)
//
//	This class is the iterator for polygonal surfaces - iterates over 
//  face vertices.
//
//	The iterator functions in two modes depending on whether a component
//	is specified. When a component is not given or is NULL the iteration
//	will be over all polygons for the surface.  When a component is given
//	this iterator will iterate over the polygons specified in the component.
//	When iterating over components a DAG path to the surface must also be
//	supplied.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES

#include <maya/MFnDagNode.h>
#include <maya/MObject.h>
#include <maya/MVector.h>
#include <maya/MPoint.h>
#include <maya/MColor.h>
#include <maya/MFloatArray.h>
#include <maya/MFloatVectorArray.h>
#include <maya/MVectorArray.h>
#include <maya/MColorArray.h>
#include <maya/MString.h>

// *****************************************************************************

// DECLARATIONS

class MPointArray;
class MDoubleArray;
class MIntArray;
class MDGModifier;

// *****************************************************************************

// CLASS DECLARATION (MItMeshFaceVertex)

/// Face vertex iterator
/**
  Iterate over face vertices of polygonal surfaces
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MItMeshFaceVertex
{
public:
	///
    MItMeshFaceVertex( const MObject & polyObject, MStatus * ReturnStatus = NULL );
    ///
    MItMeshFaceVertex( const MDagPath &polyObject,
					MObject & component = MObject::kNullObj,
					MStatus * ReturnStatus = NULL );
	///
	virtual ~MItMeshFaceVertex();
    ///
    bool        isDone( MStatus * ReturnStatus = NULL );
    ///
    MStatus     next();
    ///
    MStatus     reset();
    ///
    MStatus     reset( const MObject & polyObject );
    ///
    MStatus     reset( const MDagPath &polyObject,
						MObject & component = MObject::kNullObj );
    ///
    int         vertId( MStatus * ReturnStatus = NULL ) const;
	///	
    int         faceId( MStatus * ReturnStatus = NULL ) const;
    ///
    int         faceVertId( MStatus * ReturnStatus = NULL ) const;
	/// OBSOLETE
	MObject		faceVertex(MStatus * ReturnStatus = NULL) const;
	/// 
	MObject		currentItem(MStatus * ReturnStatus = NULL) const;

    ///
    MPoint      position( MSpace::Space space = MSpace::kObject,
						  MStatus * ReturnStatus = NULL );

    /// Get/Set methods for normals.
    MStatus     getNormal( MVector & normal,
						   MSpace::Space space = MSpace::kObject );
	/// 
    int         normalId( MStatus * ReturnStatus = NULL );

	///
    MVector     getTangent( MSpace::Space space = MSpace::kObject,
						    const MString * uvSet = NULL,
						    MStatus * ReturnStatus = NULL);

	///
    MVector     getBinormal( MSpace::Space space = MSpace::kObject,
						     const MString * uvSet = NULL,
						     MStatus * ReturnStatus = NULL);

	// UV methods. Mention sharing in docs when setUVs
	///
	bool		hasUVs( MStatus * ReturnStatus = NULL ) const;
    /// 
    bool        hasUVs( const MString & uvSet,
						MStatus * ReturnStatus = NULL ) const;
    /// 
    MStatus     getUV( float2 & uvPoint, const MString * uvSet = NULL) const;
    ///
    MStatus     getUVIndex( int & index, const MString *uvSet = NULL );
    ///
    MStatus     getUVIndex( int & index, float & u, float & v,
							const MString *uvSet = NULL);

	// Color methods. Mention sharing in docs when setUVs
	///
	bool		hasColor(MStatus * ReturnStatus = NULL ) const;
	///
	MStatus		getColor(MColor &color, const MString *colorSetName = NULL);
	/// 		
	MStatus		getColorIndex( int & colorIndex, const MString *colorSetName = NULL );

    ///
    MStatus     updateSurface();
    ///
    MStatus     geomChanged();
	///
	MStatus		setIndex(int faceId, int vertFaceId, 
					     int &prevFaceId, int &prevVertId );

protected:
    bool		getUVSetIndex( const MString * uvSetName,
							   int & uvSet) const;

	bool		updateColorSet(const MString *colorSetName, int& prevSetId);

	void		resetColorSetToPrevious(const MString *colorSetName, int prevSetId);

private:

    static const char*  className();
    MPtrBase *      f_shape;
    void 	 *      f_path;
    void 	 *      f_geom;
	void	 *		f_ref;

	void	 *		fCompIter;		// face vertex component iterator
	void     *      fElements;		// pointer to the vertex face component list

};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MItMeshFaceVertex */
