/*!
 *  @header EMLocationMessageBody.h
 *  @abstract Location message body
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

#import "EMMessageBody.h"

/*!
 *  Location message body
 */
@interface EMLocationMessageBody : EMMessageBody

/*!
 *  Latitude
 */
@property (nonatomic) double latitude;

/*!
 *  Longitude
 */
@property (nonatomic) double longitude;

/*!
 *  Address
 */
@property (nonatomic, copy) NSString *address;

/*!
 *  Initialize location message body instance
 *
 *  @param aLatitude   Latitude
 *  @param aLongitude  Longitude
 *  @param aAddress    Address
 *
 *  @result Location message body instance
 */
- (instancetype)initWithLatitude:(double)aLatitude
                       longitude:(double)aLongitude
                         address:(NSString *)aAddress;

@end
