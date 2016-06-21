/*!
 *  @header IEMCallManager.h
 *  @abstract This protocol defined the operations of real time voice/video call
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
 *  Remove delegate
 *
 *  @param aDelegate  Delegate
 */
- (void)removeDelegate:(id<EMCallManagerDelegate>)aDelegate;

#pragma mark - Answer and End

/*!
 *  Receiver answer the call
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
 *  Start a voice call session
 *
 *  @param aUsername  The callee
 *  @param pError     Error
 *
 *  @result Session instance
 */
- (EMCallSession *)makeVoiceCall:(NSString *)aUsername
                           error:(EMError **)pError;

/*!
 *  Get video package lost rate
 *
 *  @param aSessionId   Session ID
 *  @param aIsSilence   Is Silence
 *
 *  @result             Error
 */
- (EMError *)markCallSession:(NSString *)aSessionId
                   isSilence:(BOOL)aIsSilence;

/*!
 *  Suspend voice data transmission
 *
 *  @param aSessionId   Session ID
 */
- (void)pauseVoiceTransfer:(NSString *)aSessionId;

/*!
 *  Resume voice data transmission
 *
 *  @param aSessionId   Session ID
 */
- (void)resumeVoiceTransfer:(NSString *)aSessionId;


#pragma mark - video

/*!
 *  Start a video call session
 *
 *  @param aUsername  The callee
 *  @param pError     Error
 *
 *  @result Session instance
 */
- (EMCallSession *)makeVideoCall:(NSString *)aUsername
                           error:(EMError **)pError;

/*!
 * Suspend video data transmission
 *
 *  @param aSessionId   Session ID
 */
- (void)pauseVideoTransfer:(NSString *)aSessionId;

/*!
 *  Resume video data transmission
 *
 *  @param aSessionId   Session ID
 */
- (void)resumeVideoTransfer:(NSString *)aSessionId;

/*!
 * Suspend voice and video data transmission
 *
 *  @param aSessionId   Session ID
 */
- (void)pauseVoiceAndVideoTransfer:(NSString *)aSessionId;

/*!
 *  Resume voice and video data transmission
 *
 *  @param aSessionId   Session ID
 */
- (void)resumeVoiceAndVideoTransfer:(NSString *)aSessionId;

/*!
 *  open or close video adaptive,default is close
 *
 *  @param aFlag   YES is open,NO is close
 */
- (void)setVideoAdaptive:(BOOL)aFlag;

@end
