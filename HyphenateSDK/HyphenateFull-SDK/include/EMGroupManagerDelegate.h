/*!
 *  @header EMGroupManagerDelegate.h
 *  @abstract This protocol defined the callbacks of group
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

/*!
 *  The reason of user leaving the group
 */
typedef enum{
    EMGroupLeaveReasonBeRemoved = 0,    /*!  Removed by owner */
    EMGroupLeaveReasonUserLeave,        /*!  User leave the group */
    EMGroupLeaveReasonDestroyed,        /*!  Group has been destroyed */
}EMGroupLeaveReason;

@class EMGroup;

/*!
 *  Delegate
 */
@protocol EMGroupManagerDelegate <NSObject>

@optional

/*!
 *  Delegate method will be invoked when receiving a group invitation
 *
 *  After user A invites user B into the group, user B will receive this callback
 *
 *  @param aGroupId    The group ID
 *  @param aInviter    Inviter
 *  @param aMessage    Invitation message
 */
- (void)groupInvitationDidReceive:(NSString *)aGroupId
                          inviter:(NSString *)aInviter
                          message:(NSString *)aMessage;

/*!
 *  Delegate method will be invoked when the group invitation is accepted
 *
 *  After user B accepted user A‘s group invitation, user A will receive this callback
 *
 *  @param aGroup    User joined group
 *  @param aInvitee  Invitee
 */
- (void)groupInvitationDidAccept:(EMGroup *)aGroup
                         invitee:(NSString *)aInvitee;

/*!
 *  Delegate method will be invoked when the group invitation is decliend.
 *
 *  After user B declined user A's group invitation, user A will receive the callback
 *
 *  @param aGroup    Group instance
 *  @param aInvitee  Invitee
 *  @param aReason   Decline reason
 */
- (void)groupInvitationDidDecline:(EMGroup *)aGroup
                          invitee:(NSString *)aInvitee
                           reason:(NSString *)aReason;

/*!
 *  Delegate method will be invoked after SDK automatically accepted the group invitation
 *
 *  User B will receive this callback after SDK automatically accept user A's group invitation, need set EMOptions's isAutoAcceptGroupInvitation property to YES
 *
 *  @param aGroup    Group instance
 *  @param aInviter  Inviter
 *  @param aMessage  Invite message
 */
- (void)didJoinGroup:(EMGroup *)aGroup
             inviter:(NSString *)aInviter
             message:(NSString *)aMessage;

/*!
 *  Delegate method will be invoked when user leaves a group
 *
 *  @param aGroup    Group instance
 *  @param aReason   Leave reason
 */
- (void)didLeaveGroup:(EMGroup *)aGroup
               reason:(EMGroupLeaveReason)aReason;

/*!
 *  Delegate method will be invoked when the group owner receives a group request and group's style is EMGroupStylePublicJoinNeedApproval
 *
 *  @param aGroup     Group instance
 *  @param aUsername  The user initialized the group join request
 *  @param aReason    The user's message
 */
- (void)joinGroupRequestDidReceive:(EMGroup *)aGroup
                              user:(NSString *)aUsername
                            reason:(NSString *)aReason;

/*!
 *  Delegate method will be invoked when the group owner declines a join group request
 *
 *  User A will receive this callback after group's owner declined the group request, group's style is EMGroupStylePublicJoinNeedApproval
 *
 *  @param aGroupId    Group id
 *  @param aReason     Decline reason
 */
- (void)joinGroupRequestDidDecline:(NSString *)aGroupId
                            reason:(NSString *)aReason;

/*!
 *  Delegate method will be invoked when the group owner approves a join group request
 *
 *  User A will receive this callback after group's owner approve the group request, group's style is EMGroupStylePublicJoinNeedApproval
 *
 *  @param aGroup   Group instance
 */
- (void)joinGroupRequestDidApprove:(EMGroup *)aGroup;

/*!
 *  Group List updated
 *
 *  @param aGroupList  Group list<EMGroup>
 */
- (void)groupListDidUpdate:(NSArray *)aGroupList;

@end
