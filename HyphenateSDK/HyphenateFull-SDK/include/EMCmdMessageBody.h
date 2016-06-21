/*!
 *  @header EMCmdMessageBody.h
 *  @abstract Command message body
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

#import "EMMessageBody.h"

/*!
 *  Command message body
 */
@interface EMCmdMessageBody : EMMessageBody

/*!
 *  Command content
 */
@property (nonatomic, copy) NSString *action;

/*!
 *  Command parameters, only for compatable with old version, use EMMessage's extend attribute instead
 */
@property (nonatomic, copy) NSArray *params;

/*!
 *  Initialize command message body
 *
 *  @param aAction  Action content
 *
 *  @result Instance of command message body
 */
- (instancetype)initWithAction:(NSString *)aAction;

@end
