/*!
 *  @header EMImageMessageBody.h
 *  @abstract Image message body
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

#import "EMFileMessageBody.h"

/*!
 *  Image message body
 */
@interface EMImageMessageBody : EMFileMessageBody

/*!
 *  Size of image attachment
 */
@property (nonatomic) CGSize size;

/*!
 *  Image compression ratio. 1.0 without compression, default value is 0.6. SDK uses the default value if the given value is less than zero.
 */
@property (nonatomic) CGFloat compressRatio __deprecated_msg("Use - compressionRatio");

@property (nonatomic) CGFloat compressionRatio;

/*!
 *  Display name of thumbnail
 */
@property (nonatomic, copy) NSString *thumbnailDisplayName;

/*!
 *  Local path of thumbnail
 */
@property (nonatomic, copy) NSString *thumbnailLocalPath;

/*!
 *  Server path of thumbnail
 */
@property (nonatomic, copy) NSString *thumbnailRemotePath;

/*!
 *  Secret key for downloading a thumbnail image
 */
@property (nonatomic, copy) NSString *thumbnailSecretKey;

/*!
 *  Size of a thumbnail
 */
@property (nonatomic) CGSize thumbnailSize;

/*!
 *  File length of a thumbnail, in bytes
 */
@property (nonatomic) long long thumbnailFileLength;

/*!
 *  Download status of a thumbnail
 */
@property (nonatomic)EMDownloadStatus thumbnailDownloadStatus;

/*!
 *  Initialize an image message body instance
 *
 *  @param aData          The data of image
 *  @param aThumbnailData The data of thumbnail
 *
 *  @result An image message body instance
 */
- (instancetype)initWithData:(NSData *)aData
               thumbnailData:(NSData *)aThumbnailData;

@end
