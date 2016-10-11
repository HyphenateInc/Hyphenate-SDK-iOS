/*!
 *  @header EMError.h
 *  @abstract SDK defined error
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

#import "EMErrorCode.h"

/*!
 *  SDK defined error
 */
@interface EMError : NSObject

/*!
 *  Error code
 */
@property (nonatomic) EMErrorCode code;

/*!
 *  Error description
 */
@property (nonatomic, copy) NSString *errorDescription;


/*!
 *  Initialize an error instance
 *
 *  @param aDescription  Error description
 *  @param aCode         Error code
 *
 *  @result Error instance
 */
- (instancetype)initWithDescription:(NSString *)aDescription
                               code:(EMErrorCode)aCode;

/*!
 *  Create a error instance
 *
 *  @param aDescription  Error description
 *  @param aCode         Error code
 *
 *  @result Error instance
 */
+ (instancetype)errorWithDescription:(NSString *)aDescription
                                code:(EMErrorCode)aCode;

@end
