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
 *  Command parameters, only compatable with old sdk versions. For SDK version 3.0+, use EMMessage's ext property instead
 */
@property (nonatomic, copy) NSArray *params;

/*!
 *  Construct command message body
 *
 *  @param aAction  Action content
 *
 *  @result Instance of command message body
 */
- (instancetype)initWithAction:(NSString *)aAction;

@end
