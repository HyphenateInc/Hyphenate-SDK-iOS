/*!
 *  @header EMClient+Call.h
 *  @abstract Client call extension
 *  @author Hyphenate
 *  @version 3.00
 */

#import "EMClient.h"

#import "IEMCallManager.h"

@interface EMClient (Call)

/*!
 *  call module
 */
@property (strong, nonatomic, readonly) id<IEMCallManager> callManager;

@end
