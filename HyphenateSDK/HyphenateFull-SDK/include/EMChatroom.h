/*!
 *  @header EMChatroom.h
 *  @abstract Chatroom
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

/*!
 *  Chat room object
 */
@interface EMChatroom : NSObject

/*!
 *  Chat room id
 */
@property (nonatomic, copy, readonly) NSString *chatroomId;

/*!
 *  Subject of chat room
 */
@property (nonatomic, copy, readonly) NSString *subject;

/*!
 *  Description of chat room
 */
@property (nonatomic, copy, readonly) NSString *description;

/*!
 *  Owner of the chat room. Only one owner per chat room. 
 */
@property (nonatomic, copy, readonly) NSString *owner;

/*!
 *  The total number of members in the chat room
 */
@property (nonatomic, readonly) NSInteger occupantsCount __deprecated_msg("Use - membersCount");
@property (nonatomic, readonly) NSInteger membersCount;

/*!
 *  The capacity of the chat room
 */
@property (nonatomic, readonly) NSInteger maxOccupantsCount __deprecated_msg("Use - maxMembersCount");
@property (nonatomic, readonly) NSInteger maxMembersCount;

/*!
 *  List of members in the chat room
 */
@property (nonatomic, copy, readonly) NSArray *occupants __deprecated_msg("Use - members");
@property (nonatomic, copy, readonly) NSArray *members;

/*!
 *  Initialize chatroom instance
 *
 *  Please use [+chatroomWithId:]
 *
 *  @result nil
 */
- (instancetype)init __deprecated_msg("Use +chatroomWithId:");

/*!
 *  Construct a chatroom instance with chatroom id
 *
 *  @param aChatroomId   Chatroom id
 *
 *  @result Chatroom instance
 */
+ (instancetype)chatroomWithId:(NSString *)aChatroomId;

@end
