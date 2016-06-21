/*!
 *  @header IEMContactManager.h
 *  @abstract This protocol defined the operations of contact
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

#import "EMContactManagerDelegate.h"

@class EMError;

/*!
 *  Operations of contact
 */
@protocol IEMContactManager <NSObject>

@required

#pragma mark - Delegate

/*!
 *  Add delegate
 *
 *  @param aDelegate  Delegate
 *  @param aQueue     The queue of call delegate method
 */
- (void)addDelegate:(id<EMContactManagerDelegate>)aDelegate
      delegateQueue:(dispatch_queue_t)aQueue;

/*!
 *  Remove delegate
 *
 *  @param aDelegate  Delegate
 */
- (void)removeDelegate:(id)aDelegate;

#pragma mark - White List

/*!
 *  Get all friends from memory
 *
 *  @result Contact list<EMGroup>
 */
- (NSArray *)getContacts;

/*!
 *  Get all the friends from the DB
 *
 *  @return Contact list<NSString>
 */
- (NSArray *)getContactsFromDB;

#pragma mark - Black List

/*!
 *  Get the blacklist from memory
 *
 *  @result Blacklist<EMGroup>
 */
- (NSArray *)getBlackList;

/*!
 *  Get the blacklist from the DB
 *
 *  @return Blacklist<NSString>
 */
- (NSArray *)getBlackListFromDB;


/*!
 *  Get all the friends from the server
 *
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 *
 */
- (void)asyncGetContactsFromServer:(void (^)(NSArray *aList))aSuccessBlock
                           failure:(void (^)(EMError *aError))aFailureBlock;

/*!
 *  Add a contact
 *
 *  @param aUsername        The user to add
 *  @param aMessage         Friend invitation message
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 *
 */
- (void)asyncAddContact:(NSString *)aUsername
                message:(NSString *)aMessage
                success:(void (^)())aSuccessBlock
                failure:(void (^)(EMError *aError))aFailureBlock;

/*!
 *  Delete friend
 *
 *  @param aUsername        The user to delete
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 *
 */
- (void)asyncDeleteContact:(NSString *)aUsername
                   success:(void (^)())aSuccessBlock
                   failure:(void (^)(EMError *aError))aFailureBlock;

/*!
 *  Get the blacklist from the server
 *
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 *
 */
- (void)asyncGetBlackListFromServer:(void (^)(NSArray *aList))aSuccessBlock
                            failure:(void (^)(EMError *aError))aFailureBlock;

/*!
 *  Add user to blacklist
 *
 *  @param aUsername        The user to add
 *  @param aBoth            Whether block messages from me to the user which is added to the black list
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 *
 */
- (void)asyncAddUserToBlackList:(NSString *)aUsername
               relationshipBoth:(BOOL)aBoth
                        success:(void (^)())aSuccessBlock
                        failure:(void (^)(EMError *aError))aFailureBlock;

/*!
 *  Remove user from blacklist
 *
 *  @param aUsername        The user to remove from blacklist
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 *
 */
- (void)asyncRemoveUserFromBlackList:(NSString *)aUsername
                             success:(void (^)())aSuccessBlock
                             failure:(void (^)(EMError *aError))aFailureBlock;

/*!
 *  Agree invitation
 *
 *  @param aUsername        Applicants
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 *
 */
- (void)asyncAcceptInvitationForUsername:(NSString *)aUsername
                                 success:(void (^)())aSuccessBlock
                                 failure:(void (^)(EMError *aError))aFailureBlock;

/*!
 *  Decline invitation
 *
 *  @param aUsername        Applicants
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 *
 */
- (void)asyncDeclineInvitationForUsername:(NSString *)aUsername
                                  success:(void (^)())aSuccessBlock
                                  failure:(void (^)(EMError *aError))aFailureBlock;

@end
