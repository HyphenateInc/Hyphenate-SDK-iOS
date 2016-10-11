/*!
 *  @header IEMGroupManager.h
 *  @abstract This protocol defines the group operations
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

#import "EMGroupManagerDelegate.h"
#import "EMGroup.h"
#import "EMGroupOptions.h"
#import "EMCursorResult.h"

/*!
 *  Group operations
 */
@protocol IEMGroupManager <NSObject>

@required

#pragma mark - Delegate

/*!
 *  Add delegate
 *
 *  @param aDelegate  Delegate
 *  @param aQueue     The queue of call delegate method
 */
- (void)addDelegate:(id<EMGroupManagerDelegate>)aDelegate
      delegateQueue:(dispatch_queue_t)aQueue;

/*!
 *  Add delegate
 *
 *  @param aDelegate  Delegate
 */
- (void)addDelegate:(id<EMGroupManagerDelegate>)aDelegate;

/*!
 *  Remove delegate
 *
 *  @param aDelegate  Delegate
 */
- (void)removeDelegate:(id)aDelegate;

#pragma mark - Get Group

/*!
 *  Get all groups
 *
 *  @result Group list<EMGroup>
 *
 */
- (NSArray *)getJoinedGroups;

/*!
 *  Get the list of groups which have disabled Apple Push Notification Service
 *
 *  @param pError  Error
 */
- (NSArray *)getGroupsWithoutPushNotification:(EMError **)pError;

#pragma mark - Async method

/**
 *  Get all of user's groups from server
 *
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)getJoinedGroupsFromServerWithCompletion:(void (^)(NSArray *aList, EMError *aError))aCompletionBlock;

/*!
 *  Get public groups with the specified range from the server
 *
 *  @param aCursor          Cursor, input nil the first time
 *  @param aPageSize        Expect result count, return all results if count is less than zero
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)getPublicGroupsFromServerWithCursor:(NSString *)aCursor
                                   pageSize:(NSInteger)aPageSize
                                 completion:(void (^)(EMCursorResult *aResult, EMError *aError))aCompletionBlock;

/*!
 *  Search public group with group id
 *
 *  @param aGroundId        Group id
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)searchPublicGroupWithId:(NSString *)aGroundId
                     completion:(void (^)(EMGroup *aGroup, EMError *aError))aCompletionBlock;

/*!
 *  Create a group
 *
 *  @param aSubject         Group subject
 *  @param aDescription     Group description
 *  @param aInvitees        Group members, without creater
 *  @param aMessage         Invitation message
 *  @param aSetting         Group options
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)createGroupWithSubject:(NSString *)aSubject
                   description:(NSString *)aDescription
                      invitees:(NSArray *)aInvitees
                       message:(NSString *)aMessage
                       setting:(EMGroupOptions *)aSetting
                    completion:(void (^)(EMGroup *aGroup, EMError *aError))aCompletionBlock;

/*!
 *  Fetch group specification
 *
 *  @param aGroupId              Group id
 *  @param aIncludeMembersList   Whether to get member list
 *  @param aCompletionBlock      The callback block of completion
 *
 */
- (void)getGroupSpecificationFromServerByID:(NSString *)aGroupID
                         includeMembersList:(BOOL)aIncludeMembersList
                                 completion:(void (^)(EMGroup *aGroup, EMError *aError))aCompletionBlock;

/*!
 *  Get group's blacklist, owner’s authority is required
 *
 *  @param aGroupId         Group id
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)getGroupBlackListFromServerByID:(NSString *)aGroupId
                             completion:(void (^)(NSArray *aList, EMError *aError))aCompletionBlock;

/*!
 *  Invite User to join a group
 *
 *  @param aUsers           Invited users
 *  @param aGroupId         Group id
 *  @param aMessage         Welcome message
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)addMembers:(NSArray *)aUsers
           toGroup:(NSString *)aGroupId
           message:(NSString *)aMessage
        completion:(void (^)(EMGroup *aGroup, EMError *aError))aCompletionBlock;

/*!
 *  Remove members from a group, owner‘s authority is required
 *
 *  @param aUsers           Users to be removed
 *  @param aGroupId         Group id
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)removeMembers:(NSArray *)aUsers
            fromGroup:(NSString *)aGroupId
           completion:(void (^)(EMGroup *aGroup, EMError *aError))aCompletionBlock;

/*!
 *  Add users to group blacklist, owner‘s authority is required
 *
 *  @param aMembers         Users to be added
 *  @param aGroupId         Group id
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)blockMembers:(NSArray *)aMembers
           fromGroup:(NSString *)aGroupId
          completion:(void (^)(EMGroup *aGroup, EMError *aError))aCompletionBlock;

/*!
 *  Remove users out of group blacklist, owner‘s authority is required
 *
 *  @param aMembers         Users to be removed
 *  @param aGroupId         Group id
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)unblockMembers:(NSArray *)aMembers
             fromGroup:(NSString *)aGroupId
            completion:(void (^)(EMGroup *aGroup, EMError *aError))aCompletionBlock;

/*!
 *  Change the group subject, owner‘s authority is required
 *
 *  @param aSubject         New group‘s subject
 *  @param aGroupId         Group id
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)updateGroupSubject:(NSString *)aSubject
                  forGroup:(NSString *)aGroupId
                completion:(void (^)(EMGroup *aGroup, EMError *aError))aCompletionBlock;

/*!
 *  Change the group description, owner‘s authority is required
 *
 *  @param aDescription     New group‘s description
 *  @param aGroupId         Group id
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)updateDescription:(NSString *)aDescription
                 forGroup:(NSString *)aGroupId
               completion:(void (^)(EMGroup *aGroup, EMError *aError))aCompletionBlock;

/*!
 *  Leave a group, owner can't leave the group, can only destroy the group
 *
 *  @param aGroupId         Group id
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)leaveGroup:(NSString *)aGroupId
        completion:(void (^)(EMGroup *aGroup, EMError *aError))aCompletionBlock;

/*!
 *  Destroy a group, owner‘s authority is required
 *
 *  @param aGroupId         Group id
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)destroyGroup:(NSString *)aGroupId
          completion:(void (^)(EMGroup *aGroup, EMError *aError))aCompletionBlock;

/*!
 *  Block group messages, server blocks the messages from the group, owner can't block the group's messages
 *
 *  @param aGroupId         Group id
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)blockGroup:(NSString *)aGroupId
        completion:(void (^)(EMGroup *aGroup, EMError *aError))aCompletionBlock;

/*!
 *  Unblock group message
 *
 *  @param aGroupId         Group id
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)unblockGroup:(NSString *)aGroupId
          completion:(void (^)(EMGroup *aGroup, EMError *aError))aCompletionBlock;

/*!
 *  Join a public group, group style should be EMGroupStylePublicOpenJoin
 *
 *  @param aGroupId         Public group id
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)joinPublicGroup:(NSString *)aGroupId
            completion:(void (^)(EMGroup *aGroup, EMError *aError))aCompletionBlock;

/*!
 *  Request to join a public group, group style should be EMGroupStylePublicJoinNeedApproval
 *
 *  @param aGroupId         Public group id
 *  @param aMessage         Apply info
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)requestToJoinPublicGroup:(NSString *)aGroupId
                         message:(NSString *)aMessage
                      completion:(void (^)(EMGroup *aGroup, EMError *aError))aCompletionBlock;

/*!
 *  Approve a group request, owner‘s authority is required
 *
 *  @param aGroupId         Group id
 *  @param aUsername        Group request sender
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)approveJoinGroupRequest:(NSString *)aGroupId
                         sender:(NSString *)aUsername
                     completion:(void (^)(EMGroup *aGroup, EMError *aError))aCompletionBlock;

/*!
 *  Decline a group request, owner‘s authority is required
 *
 *  @param aGroupId         Group id
 *  @param aUsername        Group request sender
 *  @param aReason          Decline reason
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)declineJoinGroupRequest:(NSString *)aGroupId
                        sender:(NSString *)aUsername
                        reason:(NSString *)aReason
                    completion:(void (^)(EMGroup *aGroup, EMError *aError))aCompletionBlock;

/*!
 *  Accept a group invitation
 *
 *  @param groupId          Group id
 *  @param aUsername        Inviter
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)acceptInvitationFromGroup:(NSString *)aGroupId
                           inviter:(NSString *)aUsername
                        completion:(void (^)(EMGroup *aGroup, EMError *aError))aCompletionBlock;

/*!
 *  Decline a group invitation
 *
 *  @param aGroupId         Group id
 *  @param aInviter         Inviter
 *  @param aReason          Decline reason
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)declineGroupInvitation:(NSString *)aGroupId
                       inviter:(NSString *)aInviter
                        reason:(NSString *)aReason
                    completion:(void (^)(EMError *aError))aCompletionBlock;

/*!
 *  Block / unblock group message‘s push notification
 *
 *  @param aGroupId          Group id
 *  @param aIsEnable         Whether enable
 *  @param aCompletionBlock  The callback block of completion
 *
 */
- (void)updatePushServiceForGroup:(NSString *)aGroupID
                    isPushEnabled:(BOOL)aIsEnable
                       completion:(void (^)(EMGroup *aGroup, EMError *aError))aCompletionBlock;

@end
