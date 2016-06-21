/*!
 *  @header EMImageMessageBody.h
 *  @abstract Image message body
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

#import "EMFileMessageBody.h"

/*!
 *  Image message body, SDK will compress the image of message body that created by -(instancetype)initWithData:displayName: or
 *  -(instancetype)initWithData:thumbnailData before send the message
 */
@interface EMImageMessageBody : EMFileMessageBody

/*!
 *  Size of image attachment
 */
@property (nonatomic) CGSize size;

/*!
 *  Set compress ratio of image message, 1.0 without compress, default value is 0.6, 
    will use the default value if try to set a value that equal to or less than 0
 */
@property (nonatomic) CGFloat compressRatio;

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
 *  Secret key of thumbnail, need verify secret key when download thumbnail
 */
@property (nonatomic, copy) NSString *thumbnailSecretKey;

/*!
 *  Size of thumbnail
 */
@property (nonatomic) CGSize thumbnailSize;

/*!
 *  File length of thumbnail, in bytes
 */
@property (nonatomic) long long thumbnailFileLength;

/*!
 *  Download status of thumbnail
 */
@property (nonatomic)EMDownloadStatus thumbnailDownloadStatus;

/*!
 *  Initialize image message body instance
 *
 *  @param aData          The data of image
 *  @param aThumbnailData The data of thumbnail
 *
 *  @result Image message body instance
 */
- (instancetype)initWithData:(NSData *)aData
               thumbnailData:(NSData *)aThumbnailData;

@end
