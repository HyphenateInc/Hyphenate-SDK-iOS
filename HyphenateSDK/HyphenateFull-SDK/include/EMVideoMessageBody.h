/*!
 *  @header EMVideoMessageBody.h
 *  @abstract Video message body
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

#import "EMFileMessageBody.h"

/*!
 *  Video message body
 */
@interface EMVideoMessageBody : EMFileMessageBody

/*!
 *  Video duration, in seconds
 */
@property (nonatomic) int duration;

/*!
 *  Local path of thumbnail
 */
@property (nonatomic, copy) NSString *thumbnailLocalPath;

/*!
 *  Server path of thumbnail
 */
@property (nonatomic, copy) NSString *thumbnailRemotePath;

/*!
 *  Secret key of thumbnail, required to download a thumbnail
 */
@property (nonatomic, copy) NSString *thumbnailSecretKey;

/*!
 *  Size of video thumbnail
 */
@property (nonatomic) CGSize thumbnailSize;

/*!
 *  Download status of thumbnail
 */
@property (nonatomic)EMDownloadStatus thumbnailDownloadStatus;

@end
