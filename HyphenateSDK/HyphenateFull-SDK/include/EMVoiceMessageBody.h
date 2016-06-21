/*!
 *  @header EMVoiceMessageBody.h
 *  @abstract Voice message body
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

#import "EMFileMessageBody.h"

/*!
 *  Voice message body
 */
@interface EMVoiceMessageBody : EMFileMessageBody

/*!
 *  Voice duration, in seconds
 */
@property (nonatomic) int duration;

@end
