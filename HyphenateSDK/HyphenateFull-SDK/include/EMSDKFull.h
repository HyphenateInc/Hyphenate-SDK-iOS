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

#import <Hyphenate/EMClient.h>
#import <Hyphenate/EMClientDelegate.h>
#import <Hyphenate/EMClient+Call.h>

#import <Hyphenate/EMCallSession.h>

#endif


#endif /* EMSDKFull_h */
