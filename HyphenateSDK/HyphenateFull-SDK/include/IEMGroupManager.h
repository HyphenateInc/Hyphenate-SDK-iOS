/*!
 *  @header IEMGroupManager.h
 *  @abstract This protocol defined the group operations
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
 *  Remove delegate
 *
 *  @param aDelegate  Delegate
 */
- (void)removeDelegate:(id)aDelegate;

#pragma mark - Get Group

/*!
 *  Get all groups, will load from DB if not exist in memory
 *
 *  @result Group list<EMGroup>
 */
- (NSArray *)getAllGroups;

/*!
 *  Load all groups from DB, will update group list in memory after loading
 *
 *  @result Group list<EMGroup>
 */
- (NSArray *)loadAllMyGroupsFromDB;

/*!
 *  Get ID list of groups which block push from memory
 *
 *  @result Group id list<NSString>
 */
- (NSArray *)getAllIgnoredGroupIds;


/**
 *  Get all of user's groups from server, will update group list in memory and DB after success
 *
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 *
 */
- (void)asyncGetMyGroupsFromServer:(void (^)(NSArray *aList))aSuccessBlock
                           failure:(void (^)(EMError *aError))aFailureBlock;

/*!
 *  Get public groups in the specified range from the server
 *
 *  @param aCursor          Cursor, input nil the first time
 *  @param aPageSize        Expect result count, will return all results if < 0
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 *
 */
- (void)asyncGetPublicGroupsFromServerWithCursor:(NSString *)aCursor
                                        pageSize:(NSInteger)aPageSize
                                         success:(void (^)(EMCursorResult *aCursor))aSuccessBlock
                                         failure:(void (^)(EMError *aError))aFailureBlock;

/*!
 *  Search public group with the id
 *
 *  @param aGroundId        Group id
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 *
 */
- (void)asyncSearchPublicGroupWithId:(NSString *)aGroundId
                             success:(void (^)(EMGroup *aGroup))aSuccessBlock
                             failure:(void (^)(EMError *aError))aFailureBlock;

/*!
 *  Create a group
 *
 *  @param aSubject         Group subject
 *  @param aDescription     Group description
 *  @param aInvitees        Group members, without creater
 *  @param aMessage         Invitation message
 *  @param aSetting         Group options
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 *
 */
- (void)asyncCreateGroupWithSubject:(NSString *)aSubject
                        description:(NSString *)aDescription
                           invitees:(NSArray *)aInvitees
                            message:(NSString *)aMessage
                            setting:(EMGroupOptions *)aSetting
                            success:(void (^)(EMGroup *aGroup))aSuccessBlock
                            failure:(void (^)(EMError *aError))aFailureBlock;

/*!
 *  Fetch group info
 *
 *  @param aGroupId              Group id
 *  @param aIncludeMembersList   Whether get member list
 *  @param aSuccessBlock         The callback block of success
 *  @param aFailureBlock         The callback block of failure
 *
 */
- (void)asyncFetchGroupInfo:(NSString *)aGroupId
         includeMembersList:(BOOL)aIncludeMembersList
                    success:(void (^)(EMGroup *aGroup))aSuccessBlock
                    failure:(void (^)(EMError *aError))aFailureBlock;

/*!
 *  Get group‘s blacklist, need owner’s authority
 *
 *  @param aGroupId         Group id
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 *
 */
- (void)asyncFetchGroupBansList:(NSString *)aGroupId
                        success:(void (^)(NSArray *aList))aSuccessBlock
                        failure:(void (^)(EMError *aError))aFailureBlock;

/*!
 *  Invite User to join a group
 *
 *  @param aOccupants       Invited users
 *  @param aGroupId         Group id
 *  @param aWelcomeMessage  Welcome message
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 *
 */
- (void)asyncAddOccupants:(NSArray *)aOccupants
                  toGroup:(NSString *)aGroupId
           welcomeMessage:(NSString *)aWelcomeMessage
                  success:(void (^)(EMGroup *aGroup))aSuccessBlock
                  failure:(void (^)(EMError *aError))aFailureBlock;

/*!
 *  Remove members from group, need owner‘s authority
 *
 *  @param aOccupants       Users to be removed
 *  @param aGroupId         Group id
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 *
 */
- (void)asyncRemoveOccupants:(NSArray *)aOccupants
                   fromGroup:(NSString *)aGroupId
                     success:(void (^)(EMGroup *aGroup))aSuccessBlock
                     failure:(void (^)(EMError *aError))aFailureBlock;

/*!
 *  Add users to group’s blacklist, need owner‘s authority
 *
 *  @param aOccupants       Users to be added
 *  @param aGroupId         Group id
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 *
 */
- (void)asyncBlockOccupants:(NSArray *)aOccupants
                  fromGroup:(NSString *)aGroupId
                    success:(void (^)(EMGroup *aGroup))aSuccessBlock
                    failure:(void (^)(EMError *aError))aFailureBlock;

/*!
 *  Remove users from group‘s blacklist, need owner‘s authority
 *
 *  @param aOccupants       Users to be removed
 *  @param aGroupId         Group id
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 *
 */
- (void)asyncUnblockOccupants:(NSArray *)aOccupants
                     forGroup:(NSString *)aGroupId
                      success:(void (^)(EMGroup *aGroup))aSuccessBlock
                      failure:(void (^)(EMError *aError))aFailureBlock;

/*!
 *  Change group’s subject, need owner‘s authority
 *
 *  @param aSubject         New group‘s subject
 *  @param aGroupId         Group id
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 *
 */
- (void)asyncChangeGroupSubject:(NSString *)aSubject
                       forGroup:(NSString *)aGroupId
                        success:(void (^)(EMGroup *aGroup))aSuccessBlock
                        failure:(void (^)(EMError *aError))aFailureBlock;

/*!
 *  Change group’s description, need owner‘s authority
 *
 *  @param aDescription     New group‘s description
 *  @param aGroupId         Group id
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 *
 */
- (void)asyncChangeDescription:(NSString *)aDescription
                      forGroup:(NSString *)aGroupId
                       success:(void (^)(EMGroup *aGroup))aSuccessBlock
                       failure:(void (^)(EMError *aError))aFailureBlock;

/*!
 *  Leave a group, owner can't leave the group, can only destroy the group
 *
 *  @param aGroupId         Group id
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 *
 */
- (void)asyncLeaveGroup:(NSString *)aGroupId
                success:(void (^)(EMGroup *aGroup))aSuccessBlock
                failure:(void (^)(EMError *aError))aFailureBlock;

/*!
 *  Destroy a group, need owner‘s authority
 *
 *  @param aGroupId         Group id
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 *
 */
- (void)asyncDestroyGroup:(NSString *)aGroupId
                  success:(void (^)(EMGroup *aGroup))aSuccessBlock
                  failure:(void (^)(EMError *aError))aFailureBlock;

/*!
 *  Block group’s message, server will blocks the messages of the group to user, owner can't block the group's message
 *
 *  @param aGroupId         Group id
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 *
 */
- (void)asyncBlockGroup:(NSString *)aGroupId
                success:(void (^)(EMGroup *aGroup))aSuccessBlock
                failure:(void (^)(EMError *aError))aFailureBlock;

/*!
 *  Unblock group message
 *
 *  @param aGroupId         Group id
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 *
 */
- (void)asyncUnblockGroup:(NSString *)aGroupId
                  success:(void (^)(EMGroup *aGroup))aSuccessBlock
                  failure:(void (^)(EMError *aError))aFailureBlock;

/*!
 *  Join a public group, group style should be EMGroupStylePublicOpenJoin
 *
 *  @param aGroupId         Public group id
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 *
 */
- (void)asyncJoinPublicGroup:(NSString *)aGroupId
                     success:(void (^)(EMGroup *aGroup))aSuccessBlock
                     failure:(void (^)(EMError *aError))aFailureBlock;

/*!
 *  Apply to join a public group, group style should be EMGroupStylePublicJoinNeedApproval
 *
 *  @param aGroupId         Public group id
 *  @param aMessage         Apply info
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 *
 */
- (void)asyncApplyJoinPublicGroup:(NSString *)aGroupId
                          message:(NSString *)aMessage
                          success:(void (^)(EMGroup *aGroup))aSuccessBlock
                          failure:(void (^)(EMError *aError))aFailureBlock;

/*!
 *  Accept user's application, need owner‘s authority
 *
 *  @param aGroupId         Group id
 *  @param aUsername        The applicant
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 *
 */
- (void)asyncAcceptJoinApplication:(NSString *)aGroupId
                         applicant:(NSString *)aUsername
                           success:(void (^)())aSuccessBlock
                           failure:(void (^)(EMError *aError))aFailureBlock;

/*!
 *  Decline user's application, need owner‘s authority
 *
 *  @param aGroupId         Group id
 *  @param aUsername        The applicant
 *  @param aReason          Decline reason
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 *
 */
- (void)asyncDeclineJoinApplication:(NSString *)aGroupId
                          applicant:(NSString *)aUsername
                             reason:(NSString *)aReason
                            success:(void (^)())aSuccessBlock
                            failure:(void (^)(EMError *aError))aFailureBlock;

/*!
 *  Accept group's invitation
 *
 *  @param groupId          Group id
 *  @param aUsername        Inviter
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 *
 */
- (void)asyncAcceptInvitationFromGroup:(NSString *)aGroupId
                               inviter:(NSString *)aUsername
                               success:(void (^)(EMGroup *aGroup))aSuccessBlock
                               failure:(void (^)(EMError *aError))aFailureBlock;

/*!
 *  Decline a group invitation
 *
 *  @param aGroupId         Group id
 *  @param aUsername        Inviter
 *  @param aReason          Decline reason
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 *
 */
- (void)asyncDeclineInvitationFromGroup:(NSString *)aGroupId
                                inviter:(NSString *)aUsername
                                 reason:(NSString *)aReason
                                success:(void (^)())aSuccessBlock
                                failure:(void (^)(EMError *aError))aFailureBlock;

/*!
 *  Block / unblock group message‘s push notification
 *
 *  @param aGroupId          Group id
 *  @param aIgnore           Whether block
 *  @param aSuccessBlock     The callback block of success
 *  @param aFailureBlock     The callback block of failure
 *
 */
- (void)asyncIgnoreGroupPush:(NSString *)aGroupId
                      ignore:(BOOL)aIsIgnore
                     success:(void (^)())aSuccessBlock
                     failure:(void (^)(EMError *aError))aFailureBlock;

@end
