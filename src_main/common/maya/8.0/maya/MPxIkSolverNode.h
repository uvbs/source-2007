
#ifndef _MPxIkSolverNode
#define _MPxIkSolverNode
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
// CLASS:    MPxIkSolverNode
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MPxIkSolverNode)
//
//  The base class for user defined IK solvers.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES



#include <maya/MStatus.h>
#include <maya/MTypes.h>
#include <maya/MObject.h>
#include <maya/MPxNode.h>

// *****************************************************************************

// DECLARATIONS

class MString;
class MArgList;
class MIkHandleGroup;
class MMatrix;
class MDoubleArray;

// *****************************************************************************

// CLASS DECLARATION (MPxIkSolverNode)

/// Base class for user defined IK solvers  (OpenMayaAnim)
/**

Derive from this class to create user-defined IK solvers.

*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAANIM_EXPORT MPxIkSolverNode : public MPxNode
{
public:
	///
	virtual ~MPxIkSolverNode();
	///
	virtual MPxNode::Type type() const;

	///
	virtual MStatus		preSolve();
	///
	virtual MStatus		doSolve();
	///
	virtual MStatus		postSolve( MStatus );

	///
	virtual MString		solverTypeName() const;

	///
	bool				rotatePlane(MStatus *ReturnStatus = NULL) const;
	///
	MStatus				setRotatePlane(bool rotatePlane);
	///
	bool				singleChainOnly(MStatus *ReturnStatus = NULL) const;
	///
	MStatus				setSingleChainOnly(bool singleChainOnly);
	///
	bool				positionOnly(MStatus *ReturnStatus = NULL) const;
	///
	MStatus				setPositionOnly(bool positionOnly);
	///
	bool				supportJointLimits(MStatus *ReturnStatus = NULL) const;
	///
	MStatus				setSupportJointLimits(bool supportJointLimits);
	///
	bool				uniqueSolution(MStatus *ReturnStatus = NULL) const;
	///
	MStatus				setUniqueSolution(bool uniqueSolution);

	/// OBSOLETE
	virtual bool		isSingleChainOnly() const;
	/// OBSOLETE
	virtual bool		isPositionOnly() const;
	/// OBSOLETE
	virtual bool		hasJointLimitSupport() const;
	/// OBSOLETE
	virtual bool		hasUniqueSolution() const;
	/// OBSOLETE
	virtual bool		groupHandlesByTopology() const;

	///
	virtual MStatus		setFuncValueTolerance( double tolerance );
	///
	virtual MStatus		setMaxIterations( int value );

	///
	MIkHandleGroup * 	handleGroup() const;
	///
	virtual void 		setHandleGroup( MIkHandleGroup* );
	///
	const MMatrix *		toWorldSpace() const;
	///
	const MMatrix *		toSolverSpace() const;
	///
	double 				funcValueTolerance() const;
	///
	int 				maxIterations() const;
	///
	virtual void 		snapHandle( MObject& handle );

	void				create();

protected:

	///
	MStatus				getJointAngles( MDoubleArray& ) const;
	///
	MStatus				setJointAngles( const MDoubleArray& );
	///
	void				setToRestAngles();

	///
	MPxIkSolverNode();

	static const char*	className();

private:
	void*	instance;

};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MPxIkSolverNode */
