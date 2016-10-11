/*!
 *  @header EMPushOptions.h
 *  @abstract Setting options of Apple Push Notification
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

#define kPushNickname @"nickname"
#define kPushDisplayStyle @"notification_display_style"
#define kPushNoDisturbing @"notification_no_disturbing"
#define kPushNoDisturbingStartH @"notification_no_disturbing_start"
#define kPushNoDisturbingStartM @"notification_no_disturbing_startM"
#define kPushNoDisturbingEndH @"notification_no_disturbing_end"
#define kPushNoDisturbingEndM @"notification_no_disturbing_endM"

/*!
 *  Display style of push message
 */
typedef enum{
    EMPushDisplayStyleSimpleBanner = 0, /*! 
                                         *  Simply show "You have a new message"
                                         */
    EMPushDisplayStyleMessageSummary,   /*! 
                                         *  Show message's content
                                         */
}EMPushDisplayStyle;

/*!
 *  Status of Push Notification no-disturb setting
 */
typedef enum{
    EMPushNoDisturbStatusDay = 0,   /*!  The whole day */
    EMPushNoDisturbStatusCustom,    /*!  User defined period */
    EMPushNoDisturbStatusClose,     /*!  Close no-disturb mode */
}EMPushNoDisturbStatus;

/*!
 *  Apple Push Notification setting options
 */
@interface EMPushOptions : NSObject

/*!
 *  User's nickname to be displayed in apple push notification service messages
 */
@property (nonatomic, copy) NSString *nickname __deprecated_msg("Use - displayName");
@property (nonatomic, copy) NSString *displayName;

/*!
 *  Display style of notification message
 */
@property (nonatomic) EMPushDisplayStyle displayStyle;

/*!
 *  No disturbing setting of notification message
 */
@property (nonatomic) EMPushNoDisturbStatus noDisturbStatus;

/*!
 *  No disturbing mode start time (in hour)
 */
@property (nonatomic) NSInteger noDisturbingStartH;

/*!
 *  No disturbing mode end time (in hour)
 */
@property (nonatomic) NSInteger noDisturbingEndH;

@end
