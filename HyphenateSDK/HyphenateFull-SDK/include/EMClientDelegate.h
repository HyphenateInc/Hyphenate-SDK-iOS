/*!
 *  @header EMClientDelegate.h
 *  @abstract This protocol provides a number of utility classes callback
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

/*!
 *  Network Connection Status
 */
typedef enum{
    EMConnectionConnected = 0,  /*! Connected */
    EMConnectionDisconnected,   /*! Not connected */
}EMConnectionState;

@class EMError;

/*!
 *  @abstract This protocol provides a number of utility classes callback
 */
@protocol EMClientDelegate <NSObject>

@optional

/*!
 *  Connection to the server status changes will receive the callback
 *  
 *  calling the method causes:
 *  1. After successful login, the phone can not access
 *  2. After a successful login, network status change
 *  
 *  @param aConnectionState Current state
 */
- (void)didConnectionStateChanged:(EMConnectionState)aConnectionState;

/*!
 *  Callback Automatic login fails
 *
 *  @param aError Error
 */
- (void)didAutoLoginWithError:(EMError *)aError;

/*!
 *  Current login account to log in on other devices will receive the callback
 */
- (void)didLoginFromOtherDevice;

/*!
 *  Current login account will receive the callback is deleted from the server
 */
- (void)didRemovedFromServer;

@end
