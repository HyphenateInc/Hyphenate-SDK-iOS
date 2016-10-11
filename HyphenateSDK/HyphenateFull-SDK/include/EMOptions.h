/*!
 *  @header EMOptions.h
 *  @abstract SDK setting options
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

/*!
 *  Log output level
 */
typedef enum {
    EMLogLevelDebug = 0, /*!  Output all logs */
    EMLogLevelWarning,   /*!  Output warnings and errors */
    EMLogLevelError      /*!  Output errors only */
} EMLogLevel;

/*!
 *  SDK setting options
 */
@interface EMOptions : NSObject

/*!
 *  Application's unique identifier
 */
@property (nonatomic, copy, readonly) NSString *appkey;

/*!
 *  Whether print log to console, default is NO
 */
@property (nonatomic, assign) BOOL enableConsoleLog;

/*!
 *  Log output level, default is EMLogLevelDebug
 */
@property (nonatomic, assign) EMLogLevel logLevel;

/*!
 *  Whether using https, default is YES
 */
@property (nonatomic, assign) BOOL usingHttps;

/*!
 *  Whether using development environment, default is NO
 *
 *  Can only be set when initializing the sdk with [EMClient initializeSDKWithOptions:], can't be altered in runtime.
 */
@property (nonatomic, assign) BOOL isSandboxMode;

/*!
 *  Whether auto login, default is YES
 *
 *  Value is saved locally. When initializing the EMOptions, SDK looks for the local value first.
 */
@property (nonatomic, assign) BOOL isAutoLogin;

/*!
 *  Whether to delete all the group messages when leaving the group, default is YES
 */
@property (nonatomic, assign) BOOL isDeleteMessagesWhenExitGroup;

/*!
 *  Whether to delete all the chat room messages when leaving the chat room, default is YES
 */
@property (nonatomic, assign) BOOL isDeleteMessagesWhenExitChatRoom;

/*!
 *  Whether chat room's owner can leave the chat room, default is YES.
 */
@property (nonatomic, assign) BOOL isChatroomOwnerLeaveAllowed;

/*!
 *  Whether to automatically accept group invitation, default is YES
 */
@property (nonatomic, assign) BOOL isAutoAcceptGroupInvitation;

/*!
 *  Whether to automatically approve friend request, default is NO
 */
@property (nonatomic, assign) BOOL isAutoAcceptFriendInvitation;

/*!
 *  Whether to send delivery acknowledgement, default is NO. If set to YES, SDK will automatically send a delivery acknowledgement when receiving a chat message
 */
@property (nonatomic, assign) BOOL enableDeliveryAck;

/*!
 *  Whether to sort messages by server received time when loading message from database, default is YES.
 */
@property (nonatomic, assign) BOOL sortMessageByServerTime;

/*!
 *  Certificate name of Apple Push Notification Service
 *
 *  Can only be set when initializing the SDK with [EMClient initializeSDKWithOptions:], can't be altered in runtime.
 */
@property (nonatomic, copy) NSString *apnsCertName;

/*!
 *  Get a SDK setting options instance
 *
 *  @param aAppkey  App‘s unique identifier
 *
 *  @result SDK’s setting options instance
 */
+ (instancetype)optionsWithAppkey:(NSString *)aAppkey;

@end
