/*!
 *  @header EMClient.h
 *  @abstract SDK Client
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

#import "EMClientDelegate.h"
#import "EMOptions.h"
#import "EMPushOptions.h"
#import "EMError.h"

#import "IEMChatManager.h"
#import "IEMContactManager.h"
#import "IEMGroupManager.h"
#import "IEMChatroomManager.h"

/*!
 *  SDK Client
 */
@interface EMClient : NSObject
{
    EMPushOptions *_pushOptions;
}

/*!
 *  SDK version
 */
@property (nonatomic, strong, readonly) NSString *version;

/*!
 *  Current logged in user's username
 */
@property (nonatomic, strong, readonly) NSString *currentUsername;

/*!
 *  SDK setting options
 */
@property (nonatomic, strong, readonly) EMOptions *options;

/*!
 *  Apple Push Notification Service setting
 */
@property (nonatomic, strong, readonly) EMPushOptions *pushOptions;

/*!
 *  Chat Management
 */
@property (nonatomic, strong, readonly) id<IEMChatManager> chatManager;

/*!
 *  Contact Management
 */
@property (nonatomic, strong, readonly) id<IEMContactManager> contactManager;

/*!
 *  Group Management
 */
@property (nonatomic, strong, readonly) id<IEMGroupManager> groupManager;

/*!
 *  Chat room Management
 */
@property (nonatomic, strong, readonly) id<IEMChatroomManager> roomManager;

/*!
 *  If SDK will automatically log into with previously logged in session
 */
@property (nonatomic, readonly) BOOL isAutoLogin;

/*!
 *  If a user logged in
 */
@property (nonatomic, readonly) BOOL isLoggedIn;

/*!
 *  Connection status to Hyphenate IM server
 */
@property (nonatomic, readonly) BOOL isConnected;

/*!
 *  Get SDK singleton instance
 */
+ (instancetype)sharedClient;

#pragma mark - Delegate

/*!
 *  Add delegate
 *
 *  @param aDelegate  Delegate
 *  @param aQueue     The queue of calling delegate methods
 */
- (void)addDelegate:(id<EMClientDelegate>)aDelegate
      delegateQueue:(dispatch_queue_t)aQueue;

/*!
 *  Add delegate
 *
 *  @param aDelegate  Delegate
 */
- (void)addDelegate:(id<EMClientDelegate>)aDelegate;

/*!
 *  Remove delegate
 *  
 *  @param aDelegate  Delegate
 */
- (void)removeDelegate:(id)aDelegate;

#pragma mark - Initialize SDK

/*!
 *  Initialize the SDK
 *  
 *  @param aOptions  SDK setting options
 *
 *  @result Error
 */
- (EMError *)initializeSDKWithOptions:(EMOptions *)aOptions;

/*!
 *  Register a new IM user
 *
 *  To enhance the reliability, registering new IM user through REST API from backend is highly recommended
 *
 *  @param aUsername        Username
 *  @param aPassword        Password
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)registerWithUsername:(NSString *)aUsername
                    password:(NSString *)aPassword
                  completion:(void (^)(NSString *aUsername, EMError *aError))aCompletionBlock;

/*!
 *  Login
 *
 *  @param aUsername        Username
 *  @param aPassword        Password
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)loginWithUsername:(NSString *)aUsername
                 password:(NSString *)aPassword
               completion:(void (^)(NSString *aUsername, EMError *aError))aCompletionBlock;

/*!
 *  Logout
 *
 *  @param aIsUnbindDeviceToken Unbind device token to disable the Apple Push Notification Service
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)logout:(BOOL)aIsUnbindDeviceToken
    completion:(void (^)(EMError *aError))aCompletionBlock;

/*!
 *  Device token binding is required to enable Apple push notification service
 *
 *  @param aDeviceToken     Device token to bind
 *  @param aCompletionBlock The callback block of completion
 */
- (void)registerForRemoteNotificationsWithDeviceToken:(NSData *)aDeviceToken
                                           completion:(void (^)(EMError *aError))aCompletionBlock;

/*!
 *  Set display name for the push notification
 *
 *  @param aDisplayName     Display name of push
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)updatePushNotifiationDisplayName:(NSString *)aDisplayName
                              completion:(void (^)(NSString *aDisplayName, EMError *aError))aCompletionBlock;
/*!
 *  Get Apple Push Notification Service options from the server
 *
 *  @param aCompletionBlock The callback block of completion
 */
- (void)getPushNotificationOptionsFromServerWithCompletion:(void (^)(EMPushOptions *aOptions, EMError *aError))aCompletionBlock;

/*!
 *  Update Apple Push Notification Service options to the server
 *
 *  @param aCompletionBlock The callback block of completion
 */
- (void)updatePushNotificationOptionsToServerWithCompletion:(void (^)(EMError *aError))aCompletionBlock;

/*!
 *  Upload log to server
 *
 *  @param aCompletionBlock The callback block of completion
 */
- (void)uploadDebugLogToServerWithCompletion:(void (^)(EMError *aError))aCompletionBlock;

#pragma mark - iOS

/*!
 *  Migrate the IM database to the latest SDK version
 *
 *  @result Return YES for success
 */
- (BOOL)migrateDatabaseToLatestSDK;

/*!
 *  Disconnect from server when app enters background
 *
 *  @param aApplication  UIApplication
 */
- (void)applicationDidEnterBackground:(id)aApplication;

/*!
 *  Re-connect to server when app enters foreground
 *
 *  @param aApplication  UIApplication
 */
- (void)applicationWillEnterForeground:(id)aApplication;

@end
