//
//  EMCallLocalView.h
//  HyphenateSDK
//
//  Created by XieYajie on 2/29/16.
//  Copyright © 2016 Hyphenate.io. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface EMCallLocalView : UIView

/*!
 *  Initialization LocalView
 *
 *  @param frame    Frame of localView
 *  @param sessionPreset    AVCaptureSession output resolution, currently support AVCaptureSessionPreset352x288 and AVCaptureSessionPreset640x480
 *
 *  @result     Returns a LocalView instance
 */
- (instancetype)initWithFrame:(CGRect)frame withSessionPreset:(NSString*)aSessionPreset;

@end
