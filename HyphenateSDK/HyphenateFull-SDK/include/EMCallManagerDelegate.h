/*!
 *  @header EMCallManagerDelegate.h
 *  @abstract This protocol defines the callbacks of voice/video calling
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

#import "EMCallSession.h"

@class EMError;

/*!
 *  Callbacks of real time voice/video
 */
@protocol EMCallManagerDelegate <NSObject>
    
@optional

/*!
 *  Delegate method will be invoked when receiving a call.
 *  User B will receive this callback after user A dial user B.
 *
 *  @param aSession  Session instance
 */
- (void)callDidReceive:(EMCallSession *)aSession;

/*!
 *  Delegate method invokes when the connection is established.
 *  Both user A and B will receive this callback.
 *
 *  @param aSession  Session instance
 */
- (void)callDidConnect:(EMCallSession *)aSession;

/*!
 *  Delegate method invokes when the outgoing call is accepted by the recipient. 
 *  User A will receive this callback after user B accept A's call.
 *
 *  @param Session instance
 */
- (void)callDidAccept:(EMCallSession *)aSession;

/*!
 *  Delegate method invokes when the other party ends the call or some error happens.
 *  1.The another party will receive this callback after user A or user B end the call.
 *  2.Both user A and B will receive this callback after error occured.
 *
 *  @param aSession  Session instance
 *  @param aOption   The reason of ending the call
 *  @param aError    EMError
 */
- (void)callDidEnd:(EMCallSession *)aSession
            reason:(EMCallEndReason)aReason
             error:(EMError *)aError;

/*!
 *  Delegate method invokes when the other party pauses or resumes the call.
 *  User A and B are on the same call, A pauses or resumes the call, B will receive this callback.
 *
 *  @param aSession  Session instance
 *  @param aType     Current call status
 */
- (void)callStateDidChange:(EMCallSession *)aSession
                      type:(EMCallStreamingStatus)aType;

/*!
 *  Delegate method invokes when the local network status changes.
 *  User A and B are on the same call, A's network status changes from active to unstable or unavailable, and A will receive the callback.
 *
 *  @param aSession  Session instance
 *  @param aStatus   Current network status
 */
- (void)callNetworkStatusDidChange:(EMCallSession *)aSession
                            status:(EMCallNetworkStatus)aStatus;
@end
