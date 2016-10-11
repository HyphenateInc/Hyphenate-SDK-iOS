/*!
 *  @header IEMCallManager.h
 *  @abstract This protocol defines the operations of real time voice/video call
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

#import "EMCallSession.h"
#import "EMCallManagerDelegate.h"

@class EMError;

/*!
 *
 */
@protocol IEMCallManager <NSObject>

@optional

#pragma mark - Delegate

/*!
 *  Add delegate
 *
 *  @param aDelegate  Delegate
 *  @param aQueue     The queue of call delegate method
 */
- (void)addDelegate:(id<EMCallManagerDelegate>)aDelegate
      delegateQueue:(dispatch_queue_t)aQueue;

/*!
 *  Add delegate
 *
 *  @param aDelegate  Delegate
 *
 */
- (void)addDelegate:(id<EMCallManagerDelegate>)aDelegate;

/*!
 *  Remove delegate
 *
 *  @param aDelegate  Delegate
 */
- (void)removeDelegate:(id<EMCallManagerDelegate>)aDelegate;

#pragma mark - Answer and End

/*!
 *  Recipient answer the incoming call
 *
 *  @param  aSessionId Session Id
 *
 *  @result Error
 */
- (EMError *)answerIncomingCall:(NSString *)aSessionId;

/*!
 *  End the call
 *
 *  @param aSessionId Session ID
 *  @param aReason    End reason
 */
- (void)endCall:(NSString *)aSessionId
         reason:(EMCallEndReason)aReason;

#pragma mark - voice

/*!
 *  Start a voice call
 *
 *  @param aUsername        The callee
 *  @param aCompletionBlock The callback of completion
 *
 */
- (void)startVoiceCall:(NSString *)aUsername
            completion:(void (^)(EMCallSession *aCallSession, EMError *aError))aCompletionBlock;

/*!
 *  Pause voice streaming
 *
 *  @param aSessionId   Session ID
 */
- (void)pauseVoiceWithSession:(NSString *)aSessionId error:(EMError**)pError;

/*!
 *  Resume voice streaming
 *
 *  @param aSessionId   Session ID
 */
- (void)resumeVoiceWithSession:(NSString *)aSessionId error:(EMError**)pError;

#pragma mark - video

/*!
 *  Start a video call
 *
 *  @param aUsername        The callee
 *  @param aSuccessBlock    The callback block of completion
 *
 */
- (void)startVideoCall:(NSString *)aUsername
            completion:(void (^)(EMCallSession *aCallSession, EMError *aError))aCompletionBlock;

/*!
 * Pause video streaming
 *
 *  @param aSessionId   Session ID
 */
- (void)pauseVideoWithSession:(NSString *)aSessionId error:(EMError**)pError;

/*!
 *  Resume video streaming
 *
 *  @param aSessionId   Session ID
 */
- (void)resumeVideoWithSession:(NSString *)aSessionId error:(EMError**)pError;

/*!
 *  Enable video adaptive, default is disable
 *
 *  @param isAdaptive   YES is enable, NO is disable
 */
- (void)enableAdaptiveBirateStreaming:(BOOL)isAdaptive;

@end
