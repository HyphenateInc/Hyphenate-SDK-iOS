/*!
 *  @header EMSDK.h
 *  @abstract Headers of SDK
 *  @author Hyphenate
 *  @version 3.00
 */

#ifndef EMSDK_h
#define EMSDK_h

#if TARGET_OS_IPHONE

#import "EMClient.h"
#import "EMClientDelegate.h"

#else

#import <Hyphenate-SDK/EMClient.h>
#import <Hyphenate-SDK/EMClientDelegate.h>

#endif


#endif /* EMSDK_h */
