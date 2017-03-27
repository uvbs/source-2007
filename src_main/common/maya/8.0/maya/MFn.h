#ifndef _MFn
#define _MFn
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
// CLASS:    MFn
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFn)
//
//  Class MFn encapsulates all type identifiers for API Function Sets.
//  These type identifiers are the basis of RTTI in the API.
//
// *****************************************************************************


// PDB--These are being added here for use by external plug-in
// writers.  This way, they won't have to include HAWExport.h
// in their plug-in code.

#ifdef _WIN32
#ifndef FND_EXPORT
#define FND_EXPORT _declspec( dllimport ) 
#endif // FND_EXPORT

#ifndef OPENMAYA_EXPORT
#define OPENMAYA_EXPORT _declspec( dllimport )
#endif // OPENMAYA_EXPORT

#else
#ifndef FND_EXPORT
#define FND_EXPORT
#endif // FND_EXPORT

#ifndef OPENMAYA_EXPORT
#define OPENMAYA_EXPORT
#endif // OPENMAYA_EXPORT
#endif // _WIN32

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES

// *****************************************************************************

// DECLARATIONS

// *****************************************************************************

// CLASS DECLARATION (MFn)


// ************************************************************************
// NOTE: New entries can be added anywhere in this file, they need not go 
// at the end.
// ************************************************************************

/// Function Set Type Identifiers
/**
 MFn encapsulates all API Function Set type identifiers used for
 RTTI in the API.
*/
class FND_EXPORT MFn  
{
public:
///
	MFn();
///
	enum Type
	{
///
		kInvalid = 0,
///
		kBase,
///
		kNamedObject,
///
		kModel,
///
		kDependencyNode,
///
		kAddDoubleLinear,
///
		kAffect,
///
		kAnimCurve,
///
		kAnimCurveTimeToAngular,
///
		kAnimCurveTimeToDistance,
///
		kAnimCurveTimeToTime,
///
		kAnimCurveTimeToUnitless,
///
		kAnimCurveUnitlessToAngular,
///
		kAnimCurveUnitlessToDistance,
///
		kAnimCurveUnitlessToTime,
///
		kAnimCurveUnitlessToUnitless,
///
		kResultCurve,
/// 
		kResultCurveTimeToAngular,
/// 
		kResultCurveTimeToDistance,
/// 
		kResultCurveTimeToTime,
/// 
		kResultCurveTimeToUnitless,
///
		kAngleBetween,
///
		kAudio, 
///
		kBackground,
///
		kColorBackground,
///
		kFileBackground,
///
		kRampBackground,
///
		kBlend,
///
		kBlendTwoAttr,
///
		kBlendWeighted,
///
		kBlendDevice,
///
		kBlendColors,
///
		kBump,
///
		kBump3d,
///
		kCameraView,
///
		kChainToSpline,
///
		kChoice, 
///
		kCondition,
///
		kContrast,
///
		kClampColor,
///
		kCreate,
///
		kAlignCurve,
///
		kAlignSurface,
///
		kAttachCurve,
///
		kAttachSurface,
///
		kAvgCurves,
///
		kAvgSurfacePoints,
///
		kAvgNurbsSurfacePoints,
///
		kBevel,
///
		kBirailSrf,
///
		kDPbirailSrf,
///
		kMPbirailSrf,
///
		kSPbirailSrf,
///
		kBoundary,
///
		kCircle,
///
		kCloseCurve,
///
		kClosestPointOnSurface,
///
		kCloseSurface,
///
		kCurveFromSurface,
///
		kCurveFromSurfaceBnd,
///
		kCurveFromSurfaceCoS,
///
		kCurveFromSurfaceIso,
///
		kCurveInfo,
///
		kDetachCurve,
///
		kDetachSurface,
///
		kExtendCurve,
///
		kExtendSurface,
///
		kExtrude,
///
		kFFblendSrf,
///
		kFFfilletSrf,
///
		kFilletCurve,
///
		kFitBspline,
///
		kFlow,
///
		kHardenPointCurve,
///
		kIllustratorCurve,
///
		kInsertKnotCrv,
///
		kInsertKnotSrf,
///
		kIntersectSurface,
///
		kNurbsTesselate,
///
		kNurbsPlane,
///
		kNurbsCube,
///
		kOffsetCos,
///
		kOffsetCurve,
///
		kPlanarTrimSrf,
///
		kPointOnCurveInfo,
///
		kPointOnSurfaceInfo,
///
		kPrimitive,
///
		kProjectCurve,
///
		kProjectTangent,
///
		kRBFsurface,
///
		kRebuildCurve,
///
		kRebuildSurface,
///
		kReverseCurve,
///
		kReverseSurface,
///
		kRevolve,
///
		kRevolvedPrimitive,
///
		kCone,
///
		kRenderCone,
///
		kCylinder,
///
		kSphere,
///
		kSkin,
///
		kStitchSrf,
///
		kSubCurve,
///
		kSurfaceInfo,
///
		kTextCurves,
///
		kTrim,
///
		kUntrim,
///
		kDagNode,
///
		kProxy,
///
		kUnderWorld,
///
		kTransform,
///
		kAimConstraint,
///
		kLookAt,
///
		kGeometryConstraint,
///
		kGeometryVarGroup,
///
		kAnyGeometryVarGroup,
///
		kCurveVarGroup,
///
		kMeshVarGroup,
///
		kSurfaceVarGroup,
///
		kIkEffector,
///
		kIkHandle,
///
		kJoint,
///
		kManipulator3D,
///
		kArrowManip,
///
		kAxesActionManip,
///
		kBallProjectionManip,
///
		kCircleManip,
///
		kScreenAlignedCircleManip,
///
		kCircleSweepManip,
///
		kConcentricProjectionManip,
///
		kCubicProjectionManip,
///
		kCylindricalProjectionManip,
///
		kDiscManip,
///
		kFreePointManip,
///
		kCenterManip,
///
		kLimitManip,
///
		kEnableManip,
///
		kFreePointTriadManip,
///
		kPropMoveTriadManip,
///
		kTowPointManip,
///
		kPolyCreateToolManip,
///
		kPolySplitToolManip,
///
		kGeometryOnLineManip,
///
		kCameraPlaneManip,
///
		kToggleOnLineManip,
///
		kStateManip,
///
		kIsoparmManip,
///
		kLineManip,
///
		kManipContainer,
///
		kAverageCurveManip,
///
		kBarnDoorManip,
///
		kBevelManip,
///
		kBlendManip,
///
		kButtonManip,
///
		kCameraManip,
///
		kCoiManip,
///
		kCpManip,
///
		kCreateCVManip,
///
		kCreateEPManip,
///
		kCurveEdManip,
///
		kCurveSegmentManip,
///
		kDirectionManip,
///
		kDofManip,
///
		kDropoffManip,
///
		kExtendCurveDistanceManip,
///
		kExtrudeManip,
///
		kIkSplineManip,
///
		kIkRPManip,
///
		kJointClusterManip,
///
		kLightManip,
///
		kMotionPathManip,
///
		kOffsetCosManip,
///
		kOffsetCurveManip,
///
		kProjectionManip,
///
		kPolyProjectionManip,
///
		kProjectionUVManip,
///
		kProjectionMultiManip,
///
		kProjectTangentManip,
///
		kPropModManip,
///
		kQuadPtOnLineManip,
///
		kRbfSrfManip,
///
		kReverseCurveManip,
///
		kReverseCrvManip,
///
		kReverseSurfaceManip,
///
		kRevolveManip,
///
		kRevolvedPrimitiveManip,
///
		kSpotManip, 
///
		kSpotCylinderManip,
///
		kTriplanarProjectionManip,  
///
		kTrsManip,
///
		kDblTrsManip,
///
		kPivotManip2D,
///
		kManip2DContainer,
///
		kPolyMoveUVManip,
///
		kPolyMappingManip,
///
		kPolyModifierManip,
///
		kPolyMoveVertexManip,
///
		kPolyVertexNormalManip,
///
		kTexSmudgeUVManip,
///
		kTexLatticeDeformManip,
///
		kTexLattice,
///
		kTrsTransManip,
///
		kTrsInsertManip,
///
		kTrsXformManip,
///
		kManipulator2D,
///
		kTranslateManip2D,
///
		kPlanarProjectionManip,
///
		kPointOnCurveManip,
///
		kTowPointOnCurveManip,
///
		kMarkerManip,
///
		kPointOnLineManip,
///
		kPointOnSurfaceManip,
///
		kTranslateUVManip,
///
		kRotateBoxManip,
///
		kRotateManip,
///
		kHandleRotateManip,
///
		kRotateLimitsManip,
///
		kScaleLimitsManip,
///
		kScaleManip,
///
		kScalingBoxManip,
///
		kScriptManip,
///
		kSphericalProjectionManip,
///
		kTextureManip3D,
///
		kToggleManip,
///
		kTranslateBoxManip,
///
		kTranslateLimitsManip,
///
		kTranslateManip,
///
		kTrimManip,
///
		kJointTranslateManip,
///
		kManipulator, 
///
		kCirclePointManip,
///
		kDimensionManip,
///
		kFixedLineManip,
///
		kLightProjectionGeometry,
///
		kLineArrowManip,
///
		kPointManip,
///
		kTriadManip,
///
		kNormalConstraint,
///
		kOrientConstraint,
///
		kPointConstraint,
///
		kParentConstraint,
///
		kPoleVectorConstraint,
///
		kScaleConstraint,
///
		kTangentConstraint,
///
		kUnknownTransform, 
///
		kWorld,
///
		kShape,
///
		kBaseLattice,
///
		kCamera,
///
		kCluster,
///
		kSoftMod,
///
		kCollision,
///
		kDummy,
///
		kEmitter,
///
		kField,
///
		kAir,
///
		kDrag,
///
		kGravity,
///
		kNewton,
///
		kRadial,    
///
		kTurbulence,
///
		kUniform,
///
		kVortex,
///
		kGeometric,
///
		kCurve,
///
		kNurbsCurve,
///
		kNurbsCurveGeom,
///
		kDimension,
///
		kAngle,
///
		kAnnotation,
///
		kDistance,
///
		kArcLength,
///
		kRadius,
///
		kParamDimension,
///
		kDirectedDisc,
///
		kRenderRect,
///
		kEnvFogShape,
///
		kLattice,
///
		kLatticeGeom,
///
		kLocator,
///
		kDropoffLocator,
///
		kMarker,
///
		kOrientationMarker,
///
		kPositionMarker,
///
		kOrientationLocator,
///
		kTrimLocator,
///
		kPlane,
///
		kSketchPlane,
///
		kGroundPlane,
///
		kOrthoGrid,
///
		kSprite,
///
		kSurface,
///
		kNurbsSurface,
///
		kNurbsSurfaceGeom,
///
		kMesh,
///
		kMeshGeom,
///
		kRenderSphere,
///
		kFlexor,
///
		kClusterFlexor,
///
		kGuideLine,
///
		kLight,
///
		kAmbientLight,
///
		kNonAmbientLight,
///
		kAreaLight,
///
		kLinearLight,
///
		kNonExtendedLight,
///
		kDirectionalLight,
///
		kPointLight,
///
		kSpotLight,
///
		kParticle,
///
		kPolyToolFeedbackShape,
///
		kRigidConstraint,
///
		kRigid,
///
		kSpring,
///
		kUnknownDag,
///
		kDefaultLightList,
///
		kDeleteComponent,
///
		kDispatchCompute,
///
		kShadingEngine,
///
		kDisplacementShader,
///
		kDistanceBetween,
///
		kDOF,
///
		kDummyConnectable,
///
		kDynamicsController,
///
		kGeoConnectable, 
///
		kExpression,
///
		kExtract, 
///
		kFilter,
///      
		kFilterClosestSample,
///
		kFilterEuler,
///
		kFilterSimplify,
///
		kGammaCorrect,
///
		kGeometryFilt,
///
		kBendLattice,
///
		kBlendShape,
///
		kBulgeLattice,
///
		kFFD,
///
		kFfdDualBase,
///
		kRigidDeform,
///
		kSculpt,
///
		kTweak,
///
		kWeightGeometryFilt,
///
		kClusterFilter,
///
		kSoftModFilter,
///
		kJointCluster,
///
		kWire,
///
		kGroupId,
///
		kGroupParts,
///
		kGuide,
///
		kHsvToRgb,
///
		kHyperGraphInfo,
///
		kHyperLayout,
///
		kHyperView,
///
		kIkSolver,
///
		kMCsolver,
///
		kPASolver,
///
		kSCsolver,
///
		kRPsolver,
///
		kSplineSolver,
///
		kIkSystem,
///
		kImagePlane,
///
		kLambert,
///
		kReflect,
///
		kBlinn,
///
		kPhong,
///   
		kPhongExplorer,
///
		kLayeredShader,
///
		kLightInfo,
///
		kLeastSquares,
///
		kLightFogMaterial,
///
		kEnvFogMaterial,
///
		kLightList,
///
		kLightSource,
///
		kLuminance,
///
		kMakeGroup,
///
		kMaterial,
///
		kDiffuseMaterial,
///
		kLambertMaterial,
///
		kBlinnMaterial,
///
		kPhongMaterial,
///
		kLightSourceMaterial,
///
		kMaterialInfo,
///
		kMatrixAdd,
///
		kMatrixHold,
///
		kMatrixMult,
///
		kMatrixPass,
///
		kMatrixWtAdd,
///
		kMidModifier,
///
		kMidModifierWithMatrix,
///
		kPolyBevel,
///
		kPolyTweak,
///
		kPolyAppend,
///
		kPolyChipOff,
///
		kPolyCloseBorder,
///
		kPolyCollapseEdge,
///
		kPolyCollapseF,
///
		kPolyCylProj,
///
		kPolyDelEdge,
///
		kPolyDelFacet,
///
		kPolyDelVertex,
///
		kPolyExtrudeFacet,
///
		kPolyMapCut,
///
		kPolyMapDel,
///
		kPolyMapSew,
///
		kPolyMergeEdge,
///
		kPolyMergeFacet,
///
		kPolyMoveEdge,
///
		kPolyMoveFacet,
///
		kPolyMoveFacetUV,
///
		kPolyMoveUV,
///
		kPolyMoveVertex,
///
		kPolyMoveVertexUV,
///
		kPolyNormal,
///
		kPolyPlanProj,
///
		kPolyProj,
///
		kPolyQuad,
///
		kPolySmooth, 
///
		kPolySoftEdge,
///
		kPolySphProj,
///
		kPolySplit,
///
		kPolySubdEdge,
///
		kPolySubdFacet,
///
		kPolyTriangulate,
///
		kPolyCreator,
///
		kPolyPrimitive,
///
		kPolyCone,
///
		kPolyCube,
///
		kPolyCylinder,
///
		kPolyMesh,
///
		kPolySphere,
///
		kPolyTorus,
///
		kPolyCreateFacet,
///
		kPolyUnite,
///
		kMotionPath,
///
		kMultilisterLight,
///
		kMultiplyDivide,
///
		kOldGeometryConstraint,
///
		kOpticalFX,
///
		kParticleAgeMapper,
///
		kParticleCloud,
///
		kParticleColorMapper,
///
		kParticleIncandecenceMapper,
///
		kParticleTransparencyMapper,
///
		kPartition, 
///
		kPlace2dTexture,
///
		kPlace3dTexture,
///
		kPluginDependNode,
///
		kPluginLocatorNode,
///   
		kPlusMinusAverage,
///
		kPointMatrixMult,
///
		kPolySeparate,
///
		kPostProcessList,
///
		kProjection,
///
		kRecord,
///
		kRenderUtilityList,
///
		kReverse,
///
		kRgbToHsv,  
///
		kRigidSolver,  
///
		kSet,
///
		kTextureBakeSet,
///
		kVertexBakeSet,
///
		kSetRange,
///
		kShaderGlow,
///
		kShaderList,
///
		kShadingMap,
///
		kSamplerInfo,
///
		kShapeFragment,
///
		kSimpleVolumeShader,
///
		kSl60,
///
		kSnapshot,
///
		kStoryBoard,
///
		kSummaryObject,
///
		kSuper,
///
		kControl,
///
		kSurfaceLuminance,
///
		kSurfaceShader,
///
		kTextureList,
///
		kTextureEnv,
///
		kEnvBall,
///
		kEnvCube,
///
		kEnvChrome,
///
		kEnvSky,
///
		kEnvSphere,
///
		kTexture2d,
///
		kBulge,
///
		kChecker,
///
		kCloth,
///
		kFileTexture,
///
		kFractal,
///
		kGrid,
///
		kMountain,
///
		kRamp,
///
		kStencil,
///
		kWater,
///
		kTexture3d,
///
		kBrownian,
///
		kCloud,
///
		kCrater, 
///
		kGranite,
///
		kLeather,
///
		kMarble,
///
		kRock,
///
		kSnow,
///
		kSolidFractal,
///
		kStucco,
///
		kTxSl,
///
		kWood,
///
		kTime,
///
		kTimeToUnitConversion,
///
		kRenderSetup,
///
		kRenderGlobals,
///
		kRenderGlobalsList,
///
		kRenderQuality,
///
		kResolution,  
///
		kHardwareRenderGlobals,
///
		kArrayMapper,
///
		kUnitConversion,
///
		kUnitToTimeConversion,
///
		kUseBackground,
///
		kUnknown,
///
		kVectorProduct,
///
		kVolumeShader,
///
		kComponent,
///
		kCurveCVComponent,
///
		kCurveEPComponent,
///
		kCurveKnotComponent,
///
		kCurveParamComponent,
///
		kIsoparmComponent,
///
		kPivotComponent,
///
		kSurfaceCVComponent,
///
		kSurfaceEPComponent,
///
		kSurfaceKnotComponent,
///
		kEdgeComponent,
///
		kLatticeComponent,
///
		kSurfaceRangeComponent,
///
		kDecayRegionCapComponent,
///
		kDecayRegionComponent,
///
		kMeshComponent,
///
		kMeshEdgeComponent,
///
		kMeshPolygonComponent,
///
		kMeshFrEdgeComponent,
///
		kMeshVertComponent,
///
		kMeshFaceVertComponent,
///
		kOrientationComponent,
///
		kSubVertexComponent,
///
		kMultiSubVertexComponent,
///
		kSetGroupComponent,
///
		kDynParticleSetComponent,
///
		kSelectionItem,
///
		kDagSelectionItem,
///
		kNonDagSelectionItem,
///
		kItemList,
///
		kAttribute,
///
		kNumericAttribute,
///
		kDoubleAngleAttribute,
///
		kFloatAngleAttribute,
///
		kDoubleLinearAttribute,
///
		kFloatLinearAttribute,
///
		kTimeAttribute,
///
		kEnumAttribute,
///
		kUnitAttribute,
///
		kTypedAttribute,
///
		kCompoundAttribute,
///
		kGenericAttribute,
///
		kLightDataAttribute,
///
		kMatrixAttribute,
///
		kFloatMatrixAttribute,
///
		kMessageAttribute,
///
		kPlugin,
///
		kData,
///
		kComponentListData,
///
		kDoubleArrayData,
///
		kIntArrayData,
///
		kLatticeData,
///
		kMatrixData,
///
		kMeshData,
///
		kNurbsSurfaceData,
///
		kNurbsCurveData,
///
		kNumericData,
///
		kData2Double,
///
		kData2Float,
///
		kData2Int,
///
		kData2Short,
///    
		kData3Double,
///
		kData3Float,
///
		kData3Int,
///
		kData3Short,
///
		kPluginData,
///
		kPointArrayData,
///
		kSphereData,
///
		kStringData,
///
		kStringArrayData,
///
		kVectorArrayData,
///
		kSelectionList,
///     
		kTransformGeometry,
///
		kCommEdgePtManip,
///
		kCommEdgeOperManip,
///
		kCommEdgeSegmentManip,
///
		kCommCornerManip,
///
		kCommCornerOperManip,
///
		kPluginDeformerNode,
///
		kTorus,
///
		kPolyBoolOp,
///
		kSingleShadingSwitch,
///
		kDoubleShadingSwitch,
///
		kTripleShadingSwitch,
///
		kNurbsSquare,
///
		kAnisotropy,
///
		kNonLinear,
///
		kDeformFunc,
///
		kDeformBend,
///
		kDeformTwist,
///
		kDeformSquash,
///
		kDeformFlare,
///
		kDeformSine,
///
		kDeformWave,
///
		kDeformBendManip,
///
		kDeformTwistManip,
///
		kDeformSquashManip,
///
		kDeformFlareManip,
///
		kDeformSineManip,
///
		kDeformWaveManip,
///
		kSoftModManip,
///
		kDistanceManip,
///
		kScript,
///
		kCurveFromMeshEdge,
///
		kCurveCurveIntersect,
///
		kNurbsCircular3PtArc,
///
		kNurbsCircular2PtArc,
///
		kOffsetSurface,
///
		kRoundConstantRadius,
///
		kRoundRadiusManip,
///
		kRoundRadiusCrvManip,
///
		kRoundConstantRadiusManip,
///
		kThreePointArcManip,
///
		kTwoPointArcManip,
///
		kTextButtonManip,
///
		kOffsetSurfaceManip,
///
		kImageData,
///
		kImageLoad,
///
		kImageSave,
///
		kImageNetSrc,
///
		kImageNetDest,
///
		kImageRender,
///
		kImageAdd,
///
		kImageDiff,
///
		kImageMultiply,
///
		kImageOver,
///
		kImageUnder,
///
		kImageColorCorrect,
///
		kImageBlur,
///
		kImageFilter,
///
		kImageDepth,
///
		kImageDisplay,
///
		kImageView,
///
		kImageMotionBlur,
///
		kMatrixFloatData,
///
		kSkinShader,
///
		kComponentManip,
///
		kSelectionListData,
///
		kObjectFilter,
///
		kObjectMultiFilter,
///
		kObjectNameFilter,
///
		kObjectTypeFilter,
///
		kObjectAttrFilter,
///
		kObjectRenderFilter,
///
		kObjectScriptFilter,
///
		kSelectionListOperator,
///
		kSubdiv,
///
		kPolyToSubdiv,
///
		kSkinClusterFilter,
///
		kCharacter,
///
		kCharacterOffset,
///
		kDagPose,
///		
		kStitchAsNurbsShell,
///
        kExplodeNurbsShell,
///
        kNurbsBoolean,
///
        kStitchSrfManip,
///		
		kForceUpdateManip,
///		
        kPluginManipContainer,
///
		kPolySewEdge,
///
		kPolyMergeVert,
///
		kPolySmoothFacet,
///
		kSmoothCurve,
///
		kGlobalStitch,
///
		kSubdivCVComponent,
///
		kSubdivEdgeComponent,
///
		kSubdivFaceComponent,
///
		kTranslateUVManip2D,
///
		kRotateUVManip2D,
///
		kScaleUVManip2D,
///
		kPolyTweakUV,
///
		kMoveUVShellManip2D,
///
		kPluginShape,
///
		kGeometryData,
///
		kSingleIndexedComponent,
///
		kDoubleIndexedComponent,
///
		kTripleIndexedComponent,
///
        kExtendSurfaceDistanceManip,
///
		kSquareSrf,
///
		kSquareSrfManip,
///
		kSubdivToPoly,
///
        kDynBase,
///
        kDynEmitterManip,
///
        kDynFieldsManip,
///
        kDynBaseFieldManip,
///
        kDynAirManip,
///
        kDynNewtonManip,
///
        kDynTurbulenceManip,
///
        kDynSpreadManip,
///
        kDynAttenuationManip,
///
        kDynArrayAttrsData,
///
        kPluginFieldNode,
///
        kPluginEmitterNode,
///
        kPluginSpringNode,
///
		kDisplayLayer,
///
		kDisplayLayerManager,
///
        kPolyColorPerVertex,
///
		kCreateColorSet,
///
		kDeleteColorSet,
///
		kCopyColorSet,
///
		kBlendColorSet,
///
		kPolyColorMod,
///
		kCharacterMappingData,
///
		kDynSweptGeometryData,
///
		kWrapFilter,
///
		kMeshVtxFaceComponent,
///
		kBinaryData,
///
		kAttribute2Double,
///
		kAttribute2Float,
///
		kAttribute2Short,
///
		kAttribute2Int,
///
		kAttribute3Double,
///
		kAttribute3Float,
///
		kAttribute3Short,
///
		kAttribute3Int,
///		
		kReference,
///		
		kBlindData,
///		
		kBlindDataTemplate,
///		
		kPolyBlindData,
///		
		kPolyNormalPerVertex,
///
		kNurbsToSubdiv,
///
		kPluginIkSolver,
///
		kInstancer,
///
		kMoveVertexManip,
///
		kStroke,
///
		kBrush,
///
		kStrokeGlobals,
///
		kPluginGeometryData,
///
		kLightLink,
///
		kDynGlobals,
///
		kPolyReduce,
///
		kLodThresholds,
///
		kChooser,
///
		kLodGroup,
///
		kMultDoubleLinear,
///
		kFourByFourMatrix,
///
		kTowPointOnSurfaceManip,
///
		kSurfaceEdManip,
///
		kSurfaceFaceComponent,
///
		kClipScheduler,
///
		kClipLibrary,
///
		kSubSurface,
///
		kSmoothTangentSrf,
///
		kRenderLayer,
///
		kRenderLayerManager,
///
		kPolyFlipEdge,
///
		kPolyExtrudeEdge,
///
		kAnimBlend,
///
		kAnimBlendInOut,
///
		kPolyAppendVertex,
///
		kUvChooser,
///
		kSubdivCompId,
///
		kVolumeAxis,
///
		kDeleteUVSet,
///
		kSubdHierBlind,
///
		kSubdBlindData,
///		
		kCharacterMap,
///
		kLayeredTexture,
///
		kSubdivCollapse,
///
		kParticleSamplerInfo,
///
		kCopyUVSet,
///
		kCreateUVSet,
///
		kClip,
///
		kPolySplitVert,
///
		kSubdivData,
///
		kSubdivGeom,
///
		kUInt64ArrayData,
///
		kPolySplitEdge,
///
		kSubdivReverseFaces,
///
		kMeshMapComponent,
///
		kSectionManip,
///
		kXsectionSubdivEdit,
///
		kSubdivToNurbs,
///
		kEditCurve,
///
		kEditCurveManip,
///
		kCrossSectionManager, 
///
		kCreateSectionManip,
///
		kCrossSectionEditManip,
///		
		kDropOffFunction,
///
		kSubdBoolean,
///
		kSubdModifyEdge,
///
		kModifyEdgeCrvManip,
///
		kModifyEdgeManip,
///
		kScalePointManip,
///
		kTransformBoxManip, 
///
		kSymmetryLocator,
///
		kSymmetryMapVector,
///
		kSymmetryMapCurve,
///
		kCurveFromSubdivEdge,
///
		kCreateBPManip, 
///
		kModifyEdgeBaseManip,
///
		kSubdExtrudeFace,
///
		kSubdivSurfaceVarGroup,
///
		kSfRevolveManip,
///
		kCurveFromSubdivFace,
///
		// The next six entries are unused
		kUnused1,
///
		kUnused2,
///
		kUnused3,
///
		kUnused4,
///
		kUnused5,
///
		kUnused6,
///
		// The next five entries are for the polyUVplus plugin
		kPolyTransfer,
///
		kPolyAverageVertex,
///
		kPolyAutoProj, 
///
		kPolyLayoutUV,
///
		kPolyMapSewMove,
///
		kSubdModifier,
///
		kSubdMoveVertex,
///
		kSubdMoveEdge,
///
		kSubdMoveFace,
///
		kSubdDelFace,
///
		kSnapshotShape,
///
		kSubdivMapComponent,
///
		kJiggleDeformer,
///
		kGlobalCacheControls,
///
		kDiskCache,
///
		kSubdCloseBorder,
///
		kSubdMergeVert,
///
		kBoxData,
///
		kBox,
///
		kRenderBox,
///
		kSubdSplitFace,
///
		kPluginAnimBlendNode,
///
		kVolumeFog,
///
		kSubdTweakUV,
///
		kSubdMapCut,
///
		kSubdLayoutUV,
///
		kSubdMapSewMove,
///
		kOcean,
///
		kVolumeNoise,
///
		kSubdAutoProj,
///
		kSubdSubdivideFace,
///
		kNoise,
///
		kAttribute4Double,
///
		kData4Double,
///
		kSubdPlanProj,
///
		kSubdTweak,
///
		kSubdProjectionManip,
///
		kSubdMappingManip,
///
		kHardwareReflectionMap,
///
		kPolyNormalizeUV,
///
		kPolyFlipUV,
///
		kHwShaderNode,
///
		kPluginHwShaderNode,
///
		kSubdAddTopology,
///
		kSubdCleanTopology,
///
		kImplicitCone,
///
		kImplicitSphere,
///
		kRampShader,
///
		kVolumeLight,
///
		kOceanShader,
///
		kBevelPlus,
///
		kStyleCurve,
///
		kPolyCut,
///
		kPolyPoke,
///
		kPolyWedgeFace,
///
		kPolyCutManipContainer,
///
		kPolyCutManip,
///
		kPolyPokeManip,
///
		kFluidTexture3D,
///
		kFluidTexture2D,
///
		kPolyMergeUV,
///
		kPolyStraightenUVBorder,
///
		kAlignManip,
///
		kPluginTransformNode,
///
		kFluid,
///
		kFluidGeom,
///	
		kFluidData,
///
		// The next three entries are for the studioImport plugin
		kSmear,
///
		kStringShadingSwitch,
///
		kStudioClearCoat,
///
		kFluidEmitter,
///
		kHeightField,
///
		kGeoConnector, 
///
		kSnapshotPath, 
///
		kPluginObjectSet,
///
		kQuadShadingSwitch,
///
		kPolyExtrudeVertex,
///
		kPairBlend,
///
		kTextManip,
///
		kViewManip,
///
		kXformManip,
///
		kMute,
///
		kConstraint,
///
		kTrimWithBoundaries,
///
		kCurveFromMeshCoM,
///
		kFollicle,
///
		kHairSystem,
///
		kRemapValue,
///
		kRemapColor,
///
		kRemapHsv,
///
		kHairConstraint,
///
		kTimeFunction,
///
		kMentalRayTexture,
///
		kObjectBinFilter,
///
		kPolySmoothProxy,
///
		kPfxGeometry,
///
		kPfxHair,
///
		kHairTubeShader,
///
		kPsdFileTexture,
///
		kKeyframeDelta,
///
		kKeyframeDeltaMove,
///
		kKeyframeDeltaScale,
///
		kKeyframeDeltaAddRemove,
///
		kKeyframeDeltaBlockAddRemove,
///
		kKeyframeDeltaInfType,
///
		kKeyframeDeltaTangent,
///
		kKeyframeDeltaWeighted,
///
		kKeyframeDeltaBreakdown,
		
///
		kPolyMirror,
///
		kPolyCreaseEdge,
///
		kHikEffector,
///
		kHikSolver,
///
		kHikHandle,
///
		kProxyManager,
///
		kPolyAutoProjManip,
///
		kPolyPrism,
///
		kPolyPyramid,
///
		kPolySplitRing,
///
		kPfxToon,
///
		kToonLineAttributes,
///
		kPolyDuplicateEdge,
///		
		// Facade types
		kFacade,
///
		kMaterialFacade,
///
		kEnvFacade,
///
		kAISEnvFacade,
///							  
		kLineModifier,
///
		kPolyArrow,
///
		kPolyPrimitiveMisc,
///
		kPolyPlatonicSolid,
///
		kPolyPipe,
///
   		kHikFloorContactMarker,
///
   		kHikGroundPlane,
///
		kPolyComponentData,
///
		kPolyHelix,
///
		kCacheFile,
///
		kHistorySwitch,
///
		kClosestPointOnMesh,
///
		kTransferAttributes,
///
		kPolyBridgeEdge,
///
		kCacheableNode,
///
		kCacheBase,
///
		kCacheBlend,
///
		kCacheTrack,
///
		kKeyframeRegionManip,
///
		kCurveNormalizerAngle,
///
		kCurveNormalizerLinear,
///
		kHyperLayoutDG,
///
		kPluginImagePlaneNode,
///
		kPluginParticleAttributeMapperNode,
///
		// This must go at the end of the list.
		kLast,

		// Copies of existing IDs for backward compatibility
		kAttribute2Long = kAttribute2Int,
		kAttribute3Long = kAttribute3Int,
		kData2Long = kData2Int,
		kData3Long = kData3Int
	};

	MFn::Type nodeType;

protected:
// No protected members

private:
// No private members

};

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MFn */
