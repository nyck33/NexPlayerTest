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


#import <Foundation/Foundation.h>
#import "NXPlayer.h"

/**
 * \ingroup types
 * \brief The characteristics of audio samples to be provided by NexAudioPostProcessingAdapter to the audio post-processor, which implements the NexAudioPostProcessingAdapterDelegate protocol.
 *
 * \since version 5.26
 */
typedef struct NexAudioPostProcessingParams {
	NXCodecID codecId;             ///< Decoder type that generates audio samples
	NSUInteger inChannels;         ///< Number of channels of the input audio samples
	NSUInteger outChannels;        ///< Number of channels of the output audio samples should be generated by the audio post-processor
	NSUInteger samplesPerChannel;  ///< Number of samples in 'pBuffer' argument of audioAdapter:processBuffer:length: method of NexAudioPostProcessingAdapterDelegate
} NexAudioPostProcessingParams;

@class NexAudioPostProcessingAdapter;

/**
 * \brief Defines the interface for the audio post-processor provided by the application.
 * \since version 5.26
 */
@protocol NexAudioPostProcessingAdapterDelegate <NSObject>
/**
 * \brief Called when NexPlayer&trade;nbsp; asks the audio post-processor instance that implements this protocol, if it can handle the audio samples described by 'params'.
 *
 * \param[in] adapter The calling NexAudioPostProcessingAdapter instance.
 * \param[in] params Describes the characteristics of audio samples, which are provided by the audioAdapter:processBuffer:length: method.
 * \since version 5.26
 */
- (BOOL) audioAdapter:(NexAudioPostProcessingAdapter *) adapter shouldPostProcessWithParams:(NexAudioPostProcessingParams) params;
/**
 * \brief Called to request the delegate to perform post-processing, if audioAdapterShouldPostProcess: returned YES.
 * \param[in] adapter The calling audio processing adapter.
 * \param[in,out] pBuffer The buffer contains samples, which are updated by the output samples after post-processing.
 * \param[in] Length The length of \c pBuffer in \c bytes.
 * \return The length of output stored in the buffer pointed by \c pBuffer, in \c bytes.
 */
- (NSUInteger) audioAdapter:(NexAudioPostProcessingAdapter *) adapter processBuffer:(void *)pBuffer length:(NSUInteger) length;

@end

/**
 * \brief This class provides the application a way to adapt an audio post-processor.
 * The audio processor can be implemented by conforming the NexAudioPostProcessingAdapterDelegate protocol.
 * \note The application is responsible for the memory residence of the instance of this class.
 *
 * \since version 5.26
 */
@interface NexAudioPostProcessingAdapter : NSObject
/**
 * \brief The \c NXPlayer instance passed in to initWithPlayer:delegate.
 * \since version 5.26
 */
@property (weak, nonatomic, readonly) NXPlayer *player;

/**
 * \brief The designated initializer.
 * \param[in] player The NXPlayer instance where the audio post-processor, \c delegate, will be attached to.
 * \param[in] delegate The audio post-processor instance in the application.
 *
 * \since version 5.26
 */
- (id) initWithNexPlayer:(NXPlayer *) player delegate:(id<NexAudioPostProcessingAdapterDelegate>) delegate;

/**
 \brief This method sets whether or not to have more than 2 audio channels (i.e. 5.1 channels), if the decoder of the codec type supports multi-channel output.
 * The value of the enable argument(YES or NO) affects the value of NexAudioPostProcessingParams::inChannels in 'params' of audioAdapter:shouldPostProcessWithParams:.
 * \param[in] enable Set to YES to enable multi-channel output from the decoder of 'codecType'.
 * \param[in] codecType The decoder type to be configured for multi-channel output.
 * \since version 5.26
 */
- (void) setMultiChannelEnabled:(BOOL) enable forCodecType:(NXCodecID) codecType;
@end
