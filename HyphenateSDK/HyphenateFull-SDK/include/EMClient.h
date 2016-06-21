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
 *  Current logined account
 */
@property (nonatomic, strong, readonly) NSString *currentUsername;

/*!
 *  SDK setting options
 */
@property (nonatomic, strong, readonly) EMOptions *options;

/*!
 *  Apple APNS setting
 */
@property (nonatomic, strong, readonly) EMPushOptions *pushOptions;

/*!
 *  Chat module
 */
@property (nonatomic, strong, readonly) id<IEMChatManager> chatManager;

/*!
 *  Contact module
 */
@property (nonatomic, strong, readonly) id<IEMContactManager> contactManager;

/*!
 *  Group module
 */
@property (nonatomic, strong, readonly) id<IEMGroupManager> groupManager;

/*!
 *  Chatroom module
 */
@property (nonatomic, strong, readonly) id<IEMChatroomManager> roomManager;

/*!
 *  Whether SDK will automatically login last logined account
 */
@property (nonatomic, readonly) BOOL isAutoLogin;

/*!
 *  Whether user has logged in
 */
@property (nonatomic, readonly) BOOL isLoggedIn;

/*!
 *  Whether has connected to chat server
 */
@property (nonatomic, readonly) BOOL isConnected;

/*!
 *  Get SDK single instance
 */
+ (instancetype)sharedClient;

#pragma mark - Delegate

/*!
 *  Add delegate
 *
 *  @param aDelegate  Delegate
 *  @param aQueue     The queue of call delegate method
 */
- (void)addDelegate:(id<EMClientDelegate>)aDelegate
      delegateQueue:(dispatch_queue_t)aQueue;

/*!
 *  Remove delegate
 *  
 *  @param aDelegate  Delegate
 */
- (void)removeDelegate:(id)aDelegate;

#pragma mark - Initialize SDK

/*!
 *  Initialization sdk
 *  
 *  @param aOptions  SDK setting options
 *
 *  @result Error
 */
- (EMError *)initializeSDKWithOptions:(EMOptions *)aOptions;


/*!
 *  Register a new user
 *
 *  It is not recommended, advise to register new user through REST API
 *
 *  @param aUsername        Username
 *  @param aPassword        Password
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 *
 */
- (void)asyncRegisterWithUsername:(NSString *)aUsername
                         password:(NSString *)aPassword
                          success:(void (^)())aSuccessBlock
                          failure:(void (^)(EMError *aError))aFailureBlock;

/*!
 *  Login
 *
 *  @param aUsername        Username
 *  @param aPassword        Password
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 *
 */
- (void)asyncLoginWithUsername:(NSString *)aUsername
                      password:(NSString *)aPassword
                       success:(void (^)())aSuccessBlock
                       failure:(void (^)(EMError *aError))aFailureBlock;

/*!
 *  Logout
 *
 *  @param aIsUnbindDeviceToken Whether unbind device token, device will don't receive message push after unbind token, if input YES, unbind failed will return error
 *
 *  @result Error
 */
- (void)asyncLogout:(BOOL)aIsUnbindDeviceToken
            success:(void (^)())aSuccessBlock
            failure:(void (^)(EMError *aError))aFailureBlock;

/*!
 *  Bind device token
 *
 *  @param aDeviceToken     Device token to bind
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 */
- (void)asyncBindDeviceToken:(NSData *)aDeviceToken
                     success:(void (^)())aSuccessBlock
                     failure:(void (^)(EMError *aError))aFailureBlock;

/*!
 *  Set nick name to show in push message
 *
 *  @param aNickname        Nickname
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 *
 */
- (void)asyncSetApnsNickname:(NSString *)aNickname
                     success:(void (^)())aSuccessBlock
                     failure:(void (^)(EMError *aError))aFailureBlock;

/*!
 *  Get apns options from the server
 *
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 */
- (void)asyncGetPushOptionsFromServer:(void (^)(EMPushOptions *aOptions))aSuccessBlock
                              failure:(void (^)(EMError *aError))aFailureBlock;

/*!
 *  Update APNS options to the server
 *
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 *
 */
- (void)asyncUpdatePushOptionsToServer:(void (^)())aSuccessBlock
                               failure:(void (^)(EMError *aError))aFailureBlock;

/*!
 *  Upload log to server
 *
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 */
- (void)asyncUploadLogToServer:(void (^)())aSuccessBlock
                       failure:(void (^)(EMError *aError))aFailureBlock;

#pragma mark - iOS

/*!
 *  iOS-specific, data migration to SDK3.0
 *
 *  Synchronization method will block the current thread
 *
 *  It's needed to call this method when update to SDK3.0, developers need to wait this method complete before DB related operations
 *
 *  @result Whether migration successful
 */
- (BOOL)dataMigrationTo3;

/*!
 *  iOS only, should call this method to disconnect from server when app enter backgroup
 *
 *  @param aApplication  UIApplication
 */
- (void)applicationDidEnterBackground:(id)aApplication;

/*!
 *  iOS only, should call this method to re-connect to server when app restore to foreground
 *
 *  @param aApplication  UIApplication
 */
- (void)applicationWillEnterForeground:(id)aApplication;


@end
