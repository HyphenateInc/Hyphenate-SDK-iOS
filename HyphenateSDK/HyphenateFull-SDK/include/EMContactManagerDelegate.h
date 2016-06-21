/*!
 *  @header EMContactManagerDelegate.h
 *  @abstract This protocol defined the callbacks of contact
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

@class EMError;

/*!
 *  Callbacks of contact
 */
@protocol EMContactManagerDelegate <NSObject>

@optional

/*!
 *  User A will receive this callback after user B agreed user A's add-friend invitation
 *
 *  @param aUsername   User B
 */
- (void)didReceiveAgreedFromUsername:(NSString *)aUsername;

/*!
 *  User A will receive this callback after user B declined user A's add-friend invitation
 *
 *  @param aUsername   User B
 */
- (void)didReceiveDeclinedFromUsername:(NSString *)aUsername;

/*!
 *  User A will receive this callback after User B delete the friend relationship between user A
 *
 *  @param aUsername   User B
 */
- (void)didReceiveDeletedFromUsername:(NSString *)aUsername;

/*!
 *  Both user A and B will receive this callback after User B agreed user A's add-friend invitation
 *
 *  @param aUsername   Another user of user‘s friend relationship
 */
- (void)didReceiveAddedFromUsername:(NSString *)aUsername;

/*!
 *  User A will receive this callback after user B requested to add user A as a friend
 *
 *  @param aUsername   User B
 *  @param aMessage    Friend invitation message
 */
- (void)didReceiveFriendInvitationFromUsername:(NSString *)aUsername
                                       message:(NSString *)aMessage;


@end
