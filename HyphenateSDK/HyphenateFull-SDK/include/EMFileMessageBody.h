/*!
 *  @header EMFileMessageBody.h
 *  @abstract File message body
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

#import "EMMessageBody.h"

/*!
 *  Message attachment download status
 */
typedef enum{
    EMDownloadStatusDownloading   = 0,  /*!  Downloading */
    EMDownloadStatusSuccessed,          /*!  Successed */
    EMDownloadStatusFailed,             /*!  Failed */
    EMDownloadStatusPending,            /*!  Pending */
}EMDownloadStatus;

/*!
 *  File message body
 */
@interface EMFileMessageBody : EMMessageBody

/*!
 *  Display name of attachment
 */
@property (nonatomic, copy) NSString *displayName;

/*!
 *  Local path of attachment
 */
@property (nonatomic, copy) NSString *localPath;

/*!
 *  Server path of attachment
 */
@property (nonatomic, copy) NSString *remotePath;

/*!
 *  Secret key for downloading the message attachment
 */
@property (nonatomic, copy) NSString *secretKey;

/*!
 *  Length of attachment, in bytes
 */
@property (nonatomic) long long fileLength;

/*!
 *  Download status of attachment
 */
@property (nonatomic) EMDownloadStatus downloadStatus;

/*!
 *   Initialize a file message body instance
 *
 *  @param aLocalPath   Local path of the attachment
 *  @param aDisplayName Display name of the attachment
 *
 *  @result File message body instance
 */
- (instancetype)initWithLocalPath:(NSString *)aLocalPath
                      displayName:(NSString *)aDisplayName;

/*!
 *  Initialize a file message body instance
 *
 *  @param aData        The data of attachment file
 *  @param aDisplayName Display name of the attachment
 *
 *  @result File message body instance
 */
- (instancetype)initWithData:(NSData *)aData
                 displayName:(NSString *)aDisplayName;


@end
