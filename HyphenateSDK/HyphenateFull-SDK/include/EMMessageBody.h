/*!
 *  @header EMMessageBody.h
 *  @abstract Base class of message body
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>
#import <CoreGraphics/CGGeometry.h>

/*!
 *  Message body type
 */
typedef enum{
    EMMessageBodyTypeText   = 1,    /*!  Text */
    EMMessageBodyTypeImage,         /*!  Image */
    EMMessageBodyTypeVideo,         /*!  Video */
    EMMessageBodyTypeLocation,      /*!  Location */
    EMMessageBodyTypeVoice,         /*!  Voice */
    EMMessageBodyTypeFile,          /*!  File */
    EMMessageBodyTypeCmd,           /*!  Command */
}EMMessageBodyType;

/*!
 *  Message body
 */
@interface EMMessageBody : NSObject

/*!
 *  Message body type
 */
@property (nonatomic, readonly) EMMessageBodyType type;

@end
