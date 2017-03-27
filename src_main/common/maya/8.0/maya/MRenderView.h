#ifndef _MRenderView
#define _MRenderView
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
// CLASS:    MRenderView
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MRenderView)
//
// MRenderView is a class which provides access to the Maya Render View window.
// It allows plugins to send image data to the window in the same way that the
// Maya renderer does.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************
// INCLUDED HEADER FILES

#include <maya/MDagPath.h>

// *****************************************************************************
// DECLARATIONS

// Declaration of the pixel data type.  Each channel must be a floating point
// value in the range 0 to 255.0.
//
typedef struct RV_PIXEL {
    float    r;
    float    g;
    float    b; 
    float    a;
} RV_PIXEL;


// *****************************************************************************
// CLASS DECLARATION (MRenderView)

/// Static class providing Render View API functions (OpenMayaRender)
/**
*/
class OPENMAYARENDER_EXPORT MRenderView
{
public:

	///
	static bool doesRenderEditorExist();

	///
	static MStatus setCurrentCamera( MDagPath& camera );

	///
	static MStatus getRenderRegion( unsigned int& left, 
 									unsigned int& right, 
									unsigned int& bottom, 
									unsigned int& top );

	///
	static MStatus startRender( unsigned int width, 
								unsigned int height,
								bool doNotClearBackground = false,
								bool immediateFeedback = false );

	///
	static MStatus startRegionRender( unsigned int imageWidth, 
									  unsigned int imageHeight, 
									  unsigned int regionLeft, 
									  unsigned int regionRight, 
									  unsigned int regionBottom, 
									  unsigned int regionTop,
									  bool doNotClearBackground = false,
									  bool immediateFeedback = false );

	///
	static MStatus updatePixels( unsigned int left, 
								 unsigned int right, 
								 unsigned int bottom, 
								 unsigned int top, 
								 RV_PIXEL* pPixels );

	///
	static MStatus refresh( unsigned int left, 
							unsigned int right, 
							unsigned int bottom, 
							unsigned int top );

	///
	static MStatus endRender();

private:

	// for API error reporting
	static const char *className() { return "MRenderView"; };

};

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MRenderView */
