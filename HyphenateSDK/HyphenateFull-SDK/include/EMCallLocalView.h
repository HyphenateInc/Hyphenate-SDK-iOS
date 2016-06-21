//
//  EMCallLocalView.h
//  HyphenateSDK
//
//  Created by XieYajie on 2/29/16.
//  Copyright © 2016 easemob.com. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface EMCallLocalView : UIView

/*!
 *  Initialization LocalView
 *
 *  @param frame    frame of localView
 *  @param sessionPreset    output resolution,only support AVCaptureSessionPreset352x288 and AVCaptureSessionPreset640x480
 *
 *  @result Get instance of LocalView
 */
- (instancetype)initWithFrame:(CGRect)frame withSessionPreset:(NSString*)aSessionPreset;

@end
