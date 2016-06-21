/*!	
 *  @header   EMOptions+PrivateDeploy.h
 *  @abstract SDK setting options of private  deployment
 *  @author   Hyphenate
 *  @version  3.0
 */

#import "EMOptions.h"

@interface EMOptions (PrivateDeploy)

/*!
 *  Whether allow to use DNS, default is YES
 *
 *  Can only set when initialize SDK [EMClient initializeSDKWithOptions:], can't change it in runtime
 */
@property (nonatomic, assign) BOOL enableDnsConfig;

/*!
 *  IM server port
 *
 *  It's effective only when enableDnsConfig is NO. Can only set when initialize SDK [EMClient initializeSDKWithOptions:], can't change it in runtime
 */
@property (nonatomic, assign) int chatPort;

/*!
 *  IM server
 *
 *  It's effective only when enableDnsConfig is NO. Can only set when initialize SDK [EMClient initializeSDKWithOptions:], can't change it in runtime
 */
@property (nonatomic, strong) NSString *chatServer;

/*!
 *  REST server
 *
 *  It's effective only when enableDnsConfig is NO. Can only set when initialize SDK [EMClient initializeSDKWithOptions:], can't change it in runtime
 */
@property (nonatomic, strong) NSString *restServer;

@end
