/*!
 *  @header EMGroupManagerDelegate.h
 *  @abstract This protocol defined the callbacks of group
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

/*!
 *  The reason of leaved the group
 */
typedef enum{
    EMGroupLeaveReasonBeRemoved = 0,    /*! Removed by owner */
    EMGroupLeaveReasonUserLeave,        /*! Self leave */
    EMGroupLeaveReasonDestroyed,        /*! Group has been destroyed */
}EMGroupLeaveReason;

@class EMGroup;

/*!
 *  Callbacks of group
 */
@protocol EMGroupManagerDelegate <NSObject>

@optional

/*!
 *  After user A invites user B into the group, user B will receive this callback
 *
 *  @param aGroupId    The group ID
 *  @param aInviter    Inviter
 *  @param aMessage    Invite message
 */
- (void)didReceiveGroupInvitation:(NSString *)aGroupId
                          inviter:(NSString *)aInviter
                          message:(NSString *)aMessage;

/*!
 *  After user B accepted user A‘s group invitation, user A will receive this callback
 *
 *  @param aGroup    User joined group
 *  @param aInvitee  Invitee
 */
- (void)didReceiveAcceptedGroupInvitation:(EMGroup *)aGroup
                                  invitee:(NSString *)aInvitee;

/*!
 *  After user B declined user A's group invitation, user A will receive the callback
 *
 *  @param aGroup    Group instance
 *  @param aInvitee  Invitee
 *  @param aReason   Decline reason
 */
- (void)didReceiveDeclinedGroupInvitation:(EMGroup *)aGroup
                                  invitee:(NSString *)aInvitee
                                   reason:(NSString *)aReason;

/*!
 *  User B will receive this callback after SDK automatically accept user A's group invitation, need set EMOptions's isAutoAcceptGroupInvitation property to YES
 *
 *  @param aGroup    Group
 *  @param aInviter  Inviter
 *  @param aMessage  Invite message
 */
- (void)didJoinedGroup:(EMGroup *)aGroup
               inviter:(NSString *)aInviter
               message:(NSString *)aMessage;

/*!
 *  Callback of leave group
 *
 *  @param aGroup    Group instance
 *  @param aReason   Leave reason
 */
- (void)didReceiveLeavedGroup:(EMGroup *)aGroup
                       reason:(EMGroupLeaveReason)aReason;

/*!
 *  Group's owner receive user's applicaton of joining group, group's style is EMGroupStylePublicJoinNeedApproval
 *
 *  @param aGroup     Group
 *  @param aApplicant The applicant
 *  @param aReason    The applicant's message
 */
- (void)didReceiveJoinGroupApplication:(EMGroup *)aGroup
                             applicant:(NSString *)aApplicant
                                reason:(NSString *)aReason;

/*!
 *  User A will receive this callback after group's owner declined it's application, group's style is EMGroupStylePublicJoinNeedApproval
 *
 *  @param aGroupId    Group id
 *  @param aReason     Decline reason
 */
- (void)didReceiveDeclinedJoinGroup:(NSString *)aGroupId
                             reason:(NSString *)aReason;

/*!
 *  User A will receive this callback after group's owner accepted it's application, group's style is EMGroupStylePublicJoinNeedApproval
 *
 *  @param aGroup   Group instance
 */
- (void)didReceiveAcceptedJoinGroup:(EMGroup *)aGroup;

/*!
 *  Group List changed
 *
 *  @param aGroupList  Group list<EMGroup>
 */
- (void)didUpdateGroupList:(NSArray *)aGroupList;

@end
