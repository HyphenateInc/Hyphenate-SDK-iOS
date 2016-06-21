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
    EMLogLevelDebug = 0, /*! Output all log */
    EMLogLevelWarning,   /*! Output warning and error */
    EMLogLevelError      /*! Output error only */
} EMLogLevel;

/*!
 *  SDK setting options
 */
@interface EMOptions : NSObject

/*!
 *  Application's unique identifier
 */
@property (nonatomic, strong, readonly) NSString *appkey;

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
 *  Can only set when initialize sdk [EMClient initializeSDKWithOptions:], can't change it in runtime
 */
@property (nonatomic, assign) BOOL isSandboxMode;

/*!
 *  Whether auto login, default is YES
 *
 *  Value will be saved to the local. When initialization EMOptions, the first to get the value of the local saved
 */
@property (nonatomic, assign) BOOL isAutoLogin;

/*!
 *  Whether delete all of the group's message when leave group, default is YES
 */
@property (nonatomic, assign) BOOL isDeleteMessagesWhenExitGroup;

/*!
 *  Whether delete all of the chatroom's message when leave chatroom, default is YES
 */
@property (nonatomic, assign) BOOL isDeleteMessagesWhenExitChatRoom;

/*!
 *  Whether chatroom's owner can leave chatroom, default is YES
 */
@property (nonatomic, assign) BOOL isChatroomOwnerLeaveAllowed;

/*!
 *  Whether automatically accept group invitation, default is YES
 */
@property (nonatomic, assign) BOOL isAutoAcceptGroupInvitation;

/*!
 *  Whether automatically accept friend invitation, default is NO
 */
@property (nonatomic, assign) BOOL isAutoAcceptFriendInvitation;

/*!
 *  Whether send delivery ack, default is NO, SDK will automatically send delivery ack when receive a single chat message if it's set to YES
 */
@property (nonatomic, assign) BOOL enableDeliveryAck;

/*!
 *  Whether sort message by server time when load message from database, default is YES, sort by server time
 */
@property (nonatomic, assign) BOOL sortMessageByServerTime;

/*!
 *  iOS only, push certificate name
 *
 *  Can only set when initialize SDK [EMClient initializeSDKWithOptions:], can't change it in runtime
 */
@property (nonatomic, strong) NSString *apnsCertName;

/*!
 *  Get SDK setting options instance
 *
 *  @param aAppkey  App‘s unique identifier
 *
 *  @result SDK’s setting options instance
 */
+ (instancetype)optionsWithAppkey:(NSString *)aAppkey;

@end
