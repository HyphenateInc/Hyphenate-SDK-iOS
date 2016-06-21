/*!
 *  @header EMChatroom.h
 *  @abstract Chatroom
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

/*!
 *  Chatroom
 */
@interface EMChatroom : NSObject

/*!
 *  Chatroom id
 */
@property (nonatomic, copy, readonly) NSString *chatroomId;

/*!
 *  Subject of chatroom
 */
@property (nonatomic, copy, readonly) NSString *subject;

/*!
 *  Description of chatroom
 */
@property (nonatomic, copy, readonly) NSString *description;

/*!
 *  The maximum number of members
 */
@property (nonatomic, readonly) NSInteger maxOccupantsCount;

/*!
 *  Initialize chatroom instance
 *
 *  Please use [+chatroomWithId:]
 *
 *  @result nil
 */
- (instancetype)init __deprecated_msg("Use +chatroomWithId:");

/*!
 *  Create chatroom instance
 *
 *  @param aChatroomId   Chatroom id
 *
 *  @result Chatroom instance
 */
+ (instancetype)chatroomWithId:(NSString *)aChatroomId;

@end
