/******************************************************************************
 ______________________________________________________________________________
 |                                                                            |
 |                                                                            |
 |          Copyrightⓒ 2002-2019 NexPlayer Corp. All rights reserved.         |
 |                        http://www.nexplayer.com                            |
 |                                                                            |
 |____________________________________________________________________________|
 
 ******************************************************************************
 *  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
 *  KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR
 *  PURPOSE.
 *****************************************************************************/


/**
 * \file NexPlayerSDK.h
 *
 * This is the master header file for the NexPlayer SDK for iOS.  This file
 * merely imports the other necessary header files.
 *
 * This should be included as:
 *
 * \code
 * #import <NexPlayerSDK/NexPlayerSDK.h>
 * \endcode
 *
 * This header is for the new Objective-C API described in this documentation.
 */

// Header imports
#import "NXPlayer.h"
#import "NXPlayerView.h"
#import "NXSDKVersion.h"
#import "NXCEA608Caption.h"
#import "NXStatisticsAPI.h"
#import "NexInformativeEvent.h"
/**
 * \mainpage Introduction
 *
 * \section legal Legal Notices
 *
 * \par Disclaimer for Intellectual property
 * <i>This product is designed for general purpose, and accordingly the customer is
 * responsible for all or any of intellectual property licenses required for 
 * actual application. NexPlayer Corp. does not provide any
 * indemnification for any intellectual properties owned by third party.</i>
 * 
 * \par Copyright
 * Copyright for all documents, drawings and programs related with this 
 * specification are owned by NexPlayer Corp. All or any part of the
 * specification shall not be reproduced nor distributed without prior written 
 * approval by NexPlayer Corp. Content and configuration of all or any
 * part of the specification shall not be modified nor distributed without prior 
 * written approval by NexPlayer Corp.
 * 
 * \par
 * &copy; Copyright 2010-2019 NexPlayer Corp. All rights reserved.
 * 
 *
 *
 *
 * \section abstract Abstract
 *
 * This document describes NexPlayer&trade;&nbsp;SDK for iOS version 5.40
 * and how to use the API functions of NexPlayer&trade;&nbsp;
 * SDK v5.40.x
 *
 * \note The current API is based on Objective-C. For the best
 * development experience, and to access the newer NexPlayer&trade;&nbsp;features,
 * new applications should use the Objective-C API.  Developers are strongly encouraged to
 * migrate existing applications to the new API as well.
 * 
 * NexPlayer&trade;&nbsp;SDK adds support for modifying HTTP requests sent to servers ( \link NXPlayerDelegate::nexPlayer:onModifyHttpRequest: \endlink ) in addition to
 * recently added support for caption rendering attributes like text modes, rendering options and other rending settings,
 * for retrieving playback statistics (\link NXStatsInfo \endlink) like decoded and rendered frame rates and
 * support for user-selected caption styles (currently only for CEA 608 and WebVTT) and for custom ID3 metadata tags 
 * in addition to basic support for CEA 708 closed captions, WebVTT text tracks, and 3GPP/TTML timed text,
 * a new method, getSeekableRange, to check the range in content where seeking is possible as well as support for SmoothStreaming LiveBackOff and LiveBackOffset, support
 * for handling manifests and playlists, and descrambling modules for Piff PlayReady and Progressive Download
 * content, as well as other new features.  NexPlayer&trade;&nbsp;continues to
 * support features from earlier versions such as CEA 608 closed captions, Apple's HTTP Live Streaming (HLS),
 * MS Smooth Streaming, an interface for descrambling DRM content, and progressive
 * download.  The precise feature set available depends on the SDK edition.
 * 
 * The developers of iOS Applications benefit from NexPlayer&trade;&nbsp;SDK, which
 * allows developers to easily build custom media players, without needing to
 * worry about how content is transported. In addition, NexPlayer&trade;&nbsp;SDK is
 * reliable and robust, and has proven compatibility with international standards, 
 * without sacrificing performance.
 * 
 * \section iosSimulator  Testing with the iOS Simulator
 *
 * Please also be aware that while NexPlayer does its best to support the iOS simulator
 * for testing and development purposes, support for it is unofficial.   The simulator does not
 * emulate the hardware of actual devices but only the higher level operating system and
 * as such, no guarantees can be made about performance.  There are
 * significant well-known differences between the simulator and actual iOS devices.  All apps should be
 * tested on actual devices, not in the simulator, prior to release and frequent testing on
 * actual devices is also strongly recommended during development.
 *
 *
 * \section supported Supported Codecs, Protocols and File Formats
 * \subsection supportedCodecs Supported AV codecs and file formats
 * - Video: MPEG-4, H.264(AVC), H.265(HEVC)
 * - Audio: AAC, HE AAC, Enhanced aacPlus, WMA and AMR-NB
 * - File format: 3GP, MP4, M4A, AVI
 * \note H/W decoding only supported H.264(AVC) and H.265(HEVC).
 * H.264(AVC) Codec cannot be supported on iOS lower than v8.0.
 * H.265(HEVC) Codec cannot be supported on iOS lower than v11.0.
 * H.265(HEVC) Codec only support Main profile. (Main10 and Main Still Picture profiles are not supported.)
 *
 *
 * \subsection supportedProtocols Supported Streaming and Download methods
 * - RTSP/RTP streaming
 * - RTP over UDP
 * - RTP over TCP
 * - HTTP Download
 * - General HTTP Download and Playback
 * - 3GPP Progressive Download
 * - Vidiator XHP Redirection
 * - HTTP for Redirected RTSP streaming link
 * - HTTP for Redirected HTTP download link
 * - Apple HTTP Live streaming
 * - Live streaming link
 * - HTTP download link
 *
 *
 *
 * \section supportArch Support Architecture 64-bit only (32-bit deprecated)
 *
 * The iOS11 does not support 32bit.
 * The App Store will require all apps (including updates) to be exclusively 64-bits by June 2018.
 * The NexPlayer&trade;&nbsp;SDK includes arm64, x86_64 architectures, but no longer supports armv7, armv7s and i386.
 * Devices that support only 32-bit will no longer be supported by NexPlayer&trade;&nbsp;SDK.
 * This includes all devices before iPhone5s.
 * (iPhone5c, iPhone5, iPhone4s, iPhone4, iPhone3GS, iPad(2012), iPad mini, iPad2, iPad(2010)...)
 *
 * \section apichange API Changes in NexPlayer&trade; SDK
 *
 * The old C API is no longer supported as of version 5.19.x. Developers
 * are strongly encouraged to change to the new Objective-C API.
 *
 * \section deliv SDK Contents
 *
 * The NexPlayer&trade;&nbsp;SDK is delivered in a zip that contains the framework,
 * documentation, and sample applications.
 *
 * The <b>NexPlayer_Framework</b> folder contains the framework itself, which
 * in turn contains the headers.  
 *		
 * 
 * The SDK headers are contained within the framework, and are visible under 
 * the framework when the framework has been added to an Xcode project.  The
 * framework is in <b>NexPlayer_Framework</b> and is named <b>NexPlayerSDK.framework</b>.
 *
 * There are two sample applications:
 * - <b>sample</b> demonstates how to develop a simple UI for NexPlayer&trade;&nbsp;using the Objective-C APIs.
 *   This is the recommended way to start learning the NexPlayer&trade;&nbsp;API.
 * - <b>sample-swift</b> demonstrates how to develop a simple UI for 
 *   NexPlayer&trade;&nbsp;using the Objective-C C APIs in Swift programming 
 *   language 2.0 that requires Xcode 7.
 *
 * Both samples refer to the common framework.  When you create your own project, you may
 * refer to the framework externally, or copy it into your own project (Xcode will let you
 * choose when you drag the framework into your project).
 *
 * Applications which use the NexPlayer&trade;&nbsp;SDK should include only NexPlayerSDK.h, as follows:
 * \code 
  #import <NexPlayerSDK/NexPlayerSDK.h>
  \endcode
 *
 *
 *
 *
 *
 * \section newproj Setting up a New Xcode Project using the NexPlayer&trade; SDK
 *
 * \note From version 5.24.1, developers are strongly encouraged to use <b>Xcode 7</b> and
 * <b>iOS 9 SDK</b>.
 *
 * \warning Bitcode is not supported yet.
 * To disable Bitcode, the build option <b>Enable Bitcode</b> in the
 * Build Settings of the target of your App should be set to \c No.
 *
 * -# Create a new application.
 * -# Drag <b>NexPlayerSDK.framework</b> into the Frameworks group in Xcode.  
 * -# You may choose to reference a shared location or copy the framework into
 *     your project.
 * -# Right-click on the Frameworks group in Xcode and choose
 *       <b>Add-&gt;Existing Framework</b>, and add each of the follow
 *       frameworks, required by the NexPlayerSDK:
 *    - AudioToolbox.framework
 *    - OpenGLES.framework
 *    - Foundation.framework
 *    - QuartzCore.framework
 *    - SystemConfiguration.framework
 *    - CoreVideo.framework
 *    - CoreMedia.framework
 *    - AVFoundation.framework
 *    - VideoToolbox.framework
 *
 * -# If you wish to support older versions of iOS (prior to 9) you will need
 *     to set the iOS Deployment Target and Base SDK in Xcode.  See
 *     \ref iOSver 
 *		for details.
 * 
 *
 * For a quick start to your first application, create a \c UIViewController
 * subclass (we'll call it, for this example, \c PlayerController) and
 * simply add the following code in the \c viewDidLoad method:
 *
 * \code
- (void)viewDidLoad {
	
	self.view.backgroundColor = [UIColor blackColor];
	
	m_playerView = [[NXPlayerView alloc] initWithFrame:self.view.bounds];
	[m_playerView setAutoresizingMask:
	 UIViewAutoresizingFlexibleWidth |
	 UIViewAutoresizingFlexibleHeight];
	[self.view addSubview:m_playerView];
	
	m_playerView.player.delegate = self;
	[m_playerView.player open:@"http://your.media.com/index.m3u8"
						 mode:NXOpenModeLocalBundle
					subtitles:nil
					transport:NXTransportTypeTCP
					 autoPlay:YES];
	
}
  \endcode
 *
 * Make sure you edit the header file to indicate that this implements the
 * NXPlayerDelegate protocol:
 * \code
@interface PlayerController : UIViewController <NXPlayerDelegate> {
	NXPlayerView *m_playerView;
}
   \endcode
 *
 * And then create an instance of your \c PlayerController when your
 * application starts, and add its view to your window:
 *
 * \code
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {    
    
	playerController = [[PlayerController alloc] init];
	[self.window addSubview:playerController.view];
	[self.window makeKeyAndVisible];

	return YES;
}
   \endcode
 *
 * That's all there is to it; just make sure your HLS media URL, 
 * @"http://your.media.com/index.m3u8" for example, is availble on the network and
 * this simple program will load and play that content.
 *
 *
 * \section eventovr Handling Events
 * 
 * NexPlayer&trade;&nbsp;generates various events to notify the application of
 * changes in the player's status in real time.  This allows the
 * application to update the user interface in an appropriate manner, detect
 * the end of the content, and respond to errors.
 * 
 * Events are handled through the \ref NXPlayerDelegate protocol.  You should
 * create an object which conforms to this protocol and assign it to the
 * \c delegate property of your NXPlayer instance.
 *
 * See \ref NXPlayerDelegate for more information on handling events.
 * 
 *
 * \section cea608 Support for Subtitles and Closed Captions
 *
 * In addition to support for standard subtitle formats, this version of the SDK also
 * fully supports CEA 608 closed captions according to the specifications.  These closed
 * captions can be fully handled and displayed by the SDK or, as these
 * captions include a variety of attributes and display modes, they may be implemented
 * differently in a specific application if desired by using the NXCEA608Caption API
 * to pass updated caption information to be displayed by the final application.
 * 
 * Basic support (rendering of text) for CEA 708 closed captions, WebVTT text tracks, and 3GPP/TTML timed text
 * is also currently supported.
 *
 * Please see \ref NXCEA608Caption and \ref NXCEA608CaptionView for more information on
 * how to implement CEA 608 closed captions as well as NXPlayer::selectedCEA608Channel: for
 * selecting or disabling CEA 608 closed captions.
 *
 *
 * \section timeshift Support for Server-side Time Shift in Live Content
 *
 * This version of the NexPlayer&trade;&nbsp;SDK introduces support for server-side timeshifting
 * playback in live content.  While content is viewed live, a certain amount
 * of time in the past or future may also be available to be played, depending on the server
 * for the given content.  By checking the member \c isSeekable in NXPlayer::contentInfo to determine
 * if seeking is allowed, NexPlayer&trade;&nbsp;then uses the properties \c seekBase and \c seekableLength
 * to determine the range within the content where seek can be performed and thus within which playback may be timeshifted.
 * 
 * The method NXPlayer::getSeekableRange can also be called to determine the range in content where seeking is possible.
 *
 * Please also see NXPlayerDelegate::nexPlayer:seekableStateChangedTo:seekBase:seekableLength:, NXPlayer::getSeekableRange, 
 * and NXPlayer::seekTo: as well as the sample code for more information.
 *
 *
 * \section contrastBright  Contrast and Brightness Adjustment of Video
 *
 * The contrast and brightness adjustment of video playback is now also supported by NexPlayer&trade;&nbsp;with
 * the APIs NXPlayer::contrastAdjustment and NXPlayer::brightnessAdjustment.  Please see
 * these properties for more details.
 *
 * \note Setting value to these properties has no effect when Video Toolbox hardware
 *       accelerated decoding service is used.
 *
 * \section iOSver iOS Versions and Multitasking
 *
 * The NexPlayer&trade;&nbsp;iOS SDK is compatible with all devices running iOS
 * version 8.0 and later. However, when building your application, you must
 * set <b>Base SDK</b> to <b>iOS 9</b> or later.  If you wish to
 * support older devices, set the <b>iOS Deployment Target</b> setting to
 * <b>iOS 8.0</b>.
 *
 * With these build settings set to different values, you may get a warning
 * when you build, but that is normal and can generally be ignored.
 *
 * The NexPlayer&trade;&nbsp;SDK links to certain functions available from iOS 4.x to detect
 * when the application is suspended or sent to the background.  In this case,
 * video display is suppressed (attempting to access OpenGL to draw frames 
 * while in the background will cause iOS to kill the application).
 *
 * NexPlayer&trade;&nbsp;is weak-linked to the required functions, so it still runs
 * on older iOS versions without multi-tasking, by simply not calling those
 * functions.
 *
 * NexPlayer&trade;&nbsp;uses Audio Queues and Audio Units to play back audio on iOS.
 * Normally, iOS automatically suspends these when the application is sent to
 * the background. This automatically causes video playback to stop as well,
 * since it is timed to the audio.  That means if you want your audio and video
 * to suspend while your app is in the background, you don't need to do anything
 * special; the default behavior will work.
 *
 * If you want audio to continue playing, you will need to prevent the app
 * from completely suspending by using the appropriate iOS API functions.  The
 * exact technique is beyond the scope of this document, but can be found in the
 * iOS documentation from Apple.
 *
 *
 * \section drmdsc DRM Descrambling
 *
 * NexPlayer&trade;&nbsp; supports DRM descrambling by allowing the application
 * to assign one or more descramblers to members of NXPlayer.
 *
 * A descrambler can be the same as the NXPlayerDelegate, or can be a dedicated
 * descrambling object.
 *
 * There is an Objective-C protocol for each type of descrambler, and a
 * descrambler object must conform to the appropriate protocol.  For the most
 * part, a descrambling protocol consists only of a single descrambling method.
 *
 * The descrambling method receives pointers to
 * input and output buffers; it descrambles the data in the input buffer and
 * places the descrambled data in the output buffer.
 *
 * \warning In many cases, the input and output buffer pointers point
 * to the same location.  Your code should be able to handle cases where they
 * point to the same location, and cases when they are different.  For example
 * a typical no-op descrambling method that just outputs what it is given
 * as input might be written as follows:
 * \code
@interface MyDRMDescrambler : NSObject <NXDRMDescrambler> {
}
@end

@implementation MyDRMDescrambler
- (int) descrambleDRMForPlayer:(NXPlayer *)player 
					  dataType:(NXDRMDataType)type 
				   inputBuffer:(unsigned char *)pInputBuffer 
			   inputBufferSize:(unsigned int)uiInputBufferSize 
				  outputBuffer:(unsigned char *)pOutputBuffer 
			  outputBufferSize:(unsigned int *)puiOutputBufferSize 
{
	NSLog(@"[%@]: pInputBuffer=0x%X uiInputBufferSize=%d", 
          [self class], (unsigned int)pInputBuffer, uiInputBufferSize);
	if( pInputBuffer != pOutputBuffer )
		memcpy( pOutputBuffer, pInputBuffer, uiInputBufferSize );
	*puiOutputBufferSize = uiInputBufferSize;
	return 0;
}
@end
 * \endcode
 *
 * Different types of descramblers allow access to data at different
 * points in the decoding process.  The exact point at which the descrambling must
 * occur differs between the different DRM schemes.  In addition, some descramblers
 * have additional methods or additional method parameters that are necessary 
 * for a given type of DRM.  See the individual protocol descriptions for more 
 * information.
 *
 * \see NXDRMDescrambler
 * \see NXWMDRMDescrambler
 * \see NXAsfPlayReadyDescrambler
 * \see NXSmoothStreamFragmentDescrambler
 * \see NXHLSTSDescrambler
 * \see NXSmoothStreamPlayReadyDescrambler
 * \see NXDeceUVDescrambler
 * \see NXHLSAES128Descrambler
 *
 * \section rfio Remote File I/O
 *
 * NexPlayer&trade;&nbsp;also provides a remote file I/O interface that allows
 * an application to provide custom open, close, read and write implementations.
 * This allows an application to retrieve the file data from another source, or
 * to perform DRM descrambling on the data as it is read.
 *
 * \see ::NXRemoteFileIOInterface for details
 *
 *
 */

