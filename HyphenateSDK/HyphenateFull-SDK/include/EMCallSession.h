/*!
 *  @header EMCallSession.h
 *  @abstract Call session
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

#import "EMCallLocalView.h"
#import "EMCallRemoteView.h"

/*!
 *  Call session status
 */
typedef enum{
    EMCallSessionStatusDisconnected = 0,    /*!  Disconnected */
    EMCallSessionStatusRinging,             /*!  Callee is Ringing */
    EMCallSessionStatusConnecting,          /*!  Waiting for the recipient to pickup */
    EMCallSessionStatusConnected,           /*!  Connection is established */
    EMCallSessionStatusAccepted,            /*!  Accepted */
}EMCallSessionStatus;

/*!
 *  Call type
 */
typedef enum{
    EMCallTypeVoice = 0,    /*!  Voice call */
    EMCallTypeVideo,        /*!  Video call */
}EMCallType;

/*!
 *  Call end cause
 */
typedef enum{
    EMCallEndReasonHangup   = 0,    /*!  The recipient hung up */
    EMCallEndReasonNoResponse,      /*!  No response from recipient */
    EMCallEndReasonDecline,         /*!  The recipient declined the call */
    EMCallEndReasonBusy,            /*!  The recipient was busy */
    EMCallEndReasonFailed,          /*!  Failed to establishing the connection */
}EMCallEndReason;

/*!
 *  Call connection type
 */
typedef enum{
    EMCallConnectTypeNone = 0,  /*!  No connection */
    EMCallConnectTypeDirect,    /*!   Direct connection */
    EMCallConnectTypeRelay,     /*!  Relay connection */
}EMCallConnectType;


/*!
 *  Call status
 */
typedef enum{
    EMCallStreamStatusVoicePause = 0,  /*!  Pause voice streaming */
    EMCallStreamStatusVoiceResume,     /*!  Resume voice streaming */
    EMCallStreamStatusVideoPause,      /*!  Pause video streaming */
    EMCallStreamStatusVideoResume,     /*!  Resume video streaming */
}EMCallStreamingStatus;

/*!
 *  Call Network status
 */
typedef enum{
    EMCallNetworkStatusNormal = 0,  /*!  Network Available  */
    EMCallNetworkStatusUnstable,    /*!  Network Unstable */
    EMCallNetworkStatusNoData,      /*!  Network Unavailable */
}EMCallNetworkStatus;

/*!
 *  Call session
 */
@class EMError;
@interface EMCallSession : NSObject

/*!
 *  Unique session id
 */
@property (nonatomic, strong, readonly) NSString *sessionId;

/*!
 *  Local username
 */
@property (nonatomic, strong, readonly) NSString *username;

/*!
 *  The other party's username
 */
@property (nonatomic, strong, readonly) NSString *remoteUsername;

/*!
 *  Call type
 */
@property (nonatomic, readonly) EMCallType type;

/*!
 *  Connection type
 */
@property (nonatomic, readonly) EMCallConnectType connectType;

/*!
 *  Call session status
 */
@property (nonatomic, readonly) EMCallSessionStatus status;

/*!
 *  Local display view
 */
@property (nonatomic, strong) EMCallLocalView *localVideoView;

/*!
 *  The other party's display view
 */
@property (nonatomic, strong) EMCallRemoteView *remoteVideoView;

/*!
 *  Video bit rate, must be set before call session is started.
 *
 *  Value range is 150-1000, the default is 600.
 */
@property (nonatomic) int videoBitrate;

/*!
 *  Get voice volume of the call
 *
 *  @return Volume
 */
- (int)getVoiceVolume;

/*!
 *  Get video latency, in milliseconds, changing in real time
 *
 *  @result The delay time
 */
- (int)getVideoLatency;

/*!
 *  Get video frame rate, changing in real time
 *
 *  @result The video frame rate
 */
- (int)getVideoFrameRate;

/*!
 *  Get video package lost rate
 *
 *  @result Video package lost rate
 */
- (int)getVideoLostRateInPercent;

/*!
 *  Get video original width
 *
 *  @result Video original width
 */
- (int)getVideoWidth;

/*!
 *  Get fixed video original height
 *
 *  @result Video original height
 */
- (int)getVideoHeight;

/*!
 *  Get the other party's bitrate, changing in real time
 *
 *  @result The other party's bitrate
 */
- (int)getVideoRemoteBitrate;

/*!
 *  Get bitrate of video call, changing in real time
 *
 *  @result Bitrate of video call
 */
- (int)getVideoLocalBitrate;

/*!
 *  Get a snapshot of current video screen as jpeg picture and save to the local file system.
 *
 *  @param aPath  Saved path of picture
 */
- (void)screenCaptureToFilePath:(NSString *)aPath error:(EMError**)pError;

/*!
 *  Start recording video
 *
 *  @param aPath            File saved path
 *  @param aError           Error

 *
 */
- (void)startVideoRecordingToFilePath:(NSString*)aPath
                                error:(EMError**)aError;

/*!
 *  Stop recording video
 *
 *  @param aError           Error
 *
 */
- (NSString *)stopVideoRecording:(EMError**)aError;

/*!
 *  Use front camera or back camera, default use front
 *
 *  @param  aIsFrontCamera    YES for front camera, NO for back camera.
 */
- (void)switchCameraPosition:(BOOL)aIsFrontCamera;

@end
