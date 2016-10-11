/*!
 *  @header EMTextMessageBody.h
 *  @abstract Text message body
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

#import "EMMessageBody.h"

/*!
 *  Text message body
 */
@interface EMTextMessageBody : EMMessageBody

/*!
 *  Text content
 */
@property (nonatomic, copy, readonly) NSString *text;

/*!
 *  Initialize a text message body instance
 *
 *  @param aText   Text content
 *
 *  @result Text message body instance
 */
- (instancetype)initWithText:(NSString *)aText;

@end
