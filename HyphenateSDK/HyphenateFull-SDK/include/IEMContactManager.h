/*!
 *  @header IEMContactManager.h
 *  @abstract The protocol defines the operations of contact
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

#import "EMContactManagerDelegate.h"

@class EMError;

/*!
 *  Contact Management
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
 *  Add delegate
 *
 *  @param aDelegate  Delegate
 */
- (void)addDelegate:(id<EMContactManagerDelegate>)aDelegate;

/*!
 *  Remove delegate
 *
 *  @param aDelegate  Delegate
 */
- (void)removeDelegate:(id)aDelegate;

/*!
 *  Get all contacts
 *
 *  @result Contact list<EMGroup>
 */
- (NSArray *)getContacts;

/*!
 *  Get the blacklist of blocked users
 *
 *  @result Blacklist<EMGroup>
 */
- (NSArray *)getBlackList;

#pragma mark - Async method

/*!
 *  Get all contacts from the server
 *
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)getContactsFromServerWithCompletion:(void (^)(NSArray *aList, EMError *aError))aCompletionBlock;

/*!
 *  Add a contact
 *
 *  @param aUsername        The user to be added
 *  @param aMessage         Friend request message
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)addContact:(NSString *)aUsername
           message:(NSString *)aMessage
        completion:(void (^)(NSString *aUsername, EMError *aError))aCompletionBlock;

/*!
 *  Delete a contact
 *
 *  @param aUsername        The user to be deleted
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)deleteContact:(NSString *)aUsername
           completion:(void (^)(NSString *aUsername, EMError *aError))aCompletionBlock;

/*!
 *  Get the blacklist from the server
 *
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)getBlackListFromServerWithCompletion:(void (^)(NSArray *aList, EMError *aError))aCompletionBlock;

/*!
 *  Add a user to blacklist
 *
 *  @param aUsername        Block user
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)addUserToBlackList:(NSString *)aUsername
                completion:(void (^)(NSString *aUsername, EMError *aError))aCompletionBlock;

/*!
 *  Remove a user from blacklist
 *
 *  @param aUsername        Unblock user
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)removeUserFromBlackList:(NSString *)aUsername
                     completion:(void (^)(NSString *aUsername, EMError *aError))aCompletionBlock;

/*!
 *  Apporove a friend request
 *
 *  @param aUsername        User who initiated the friend request
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)approveFriendRequestFromUser:(NSString *)aUsername
                          completion:(void (^)(NSString *aUsername, EMError *aError))aCompletionBlock;

/*!
 *  Decline a friend request
 *
 *  @param aUsername        User who initiated the friend request
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)declineFriendRequestFromUser:(NSString *)aUsername
                          completion:(void (^)(NSString *aUsername, EMError *aError))aCompletionBlock;
@end
