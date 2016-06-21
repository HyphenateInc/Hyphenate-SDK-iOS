/*!
 *  @header EMSDKFull.h
 *  @abstract Headers of SDK contains call module
 *  @author Hyphenate
 *  @version 3.00
 */

#ifndef EMSDKFull_h
#define EMSDKFull_h

#if TARGET_OS_IPHONE

#import "EMClient.h"
#import "EMClientDelegate.h"
#import "EMClient+Call.h"

#import "EMCallSession.h"

#else

#import <HyphenateFull-SDK/EMClient.h>
#import <HyphenateFull-SDK/EMClientDelegate.h>
#import <HyphenateFull-SDK/EMClient+Call.h>

#import <HyphenateFull-SDK/EMCallSession.h>

#endif


#endif /* EMSDKFull_h */
