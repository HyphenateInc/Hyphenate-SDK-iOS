/*!	
 *  @header   EMOptions+PrivateDeploy.h
 *  @abstract SDK setting options of private deployment
 *  @author   Hyphenate
 *  @version  3.0
 */

#import "EMOptions.h"

@interface EMOptions (PrivateDeploy)

/*!
 *  Whether to allow using DNS, default is YES
 *
 *  Can only be set when initializing the SDK [EMClient initializeSDKWithOptions:], cannot be altered in runtime
 */
@property (nonatomic, assign) BOOL enableDnsConfig;

/*!
 *  IM server port
 *
 *  chatPort is Only effective when isDNSEnabled is NO. 
 *  Can only be set when initializing the SDK with [EMClient initializeSDKWithOptions:], cannot be altered in runtime
 */
@property (nonatomic, assign) int chatPort;

/*!
 *  IM server
 *
 *  chatServer is Only effective when isDNSEnabled is NO. Can only be set when initializing the SDK with [EMClient initializeSDKWithOptions:], cannot be altered in runtime
 */
@property (nonatomic, copy) NSString *chatServer;

/*!
 *  REST server
 *
 *  restServer Only effective when isDNSEnabled is NO. Can only be set when initializing the SDK with [EMClient initializeSDKWithOptions:], cannot be altered in runtime
 */
@property (nonatomic, copy) NSString *restServer;

@end
