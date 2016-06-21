/*!
 *  @header EMPushOptions.h
 *  @abstract Setting options of Apple APNS
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
 *  Status of APNS no-disturb setting
 */
typedef enum{
    EMPushNoDisturbStatusDay = 0,   /*! The whole day */
    EMPushNoDisturbStatusCustom,    /*! User defined period */
    EMPushNoDisturbStatusClose,     /*! Close no-disturb mode */
}EMPushNoDisturbStatus;

/*!
 *  Apple APNS setting options
 */
@interface EMPushOptions : NSObject

/*!
 *  Nick name to show for push message
 */
@property (nonatomic, strong) NSString *nickname;

/*!
 *  Display style of push message
 */
@property (nonatomic) EMPushDisplayStyle displayStyle;

/*!
 *  No-disturb setting of push message
 */
@property (nonatomic) EMPushNoDisturbStatus noDisturbStatus;

/*!
 *  No-disturn mode start time, only supports hour
 */
@property (nonatomic) NSInteger noDisturbingStartH;

/*!
 *  No-disturn mode end time, only supports hour
 */
@property (nonatomic) NSInteger noDisturbingEndH;

@end
