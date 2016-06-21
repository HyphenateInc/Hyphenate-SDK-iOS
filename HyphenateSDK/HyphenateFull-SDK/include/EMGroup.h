/*!
 *  @header EMGroup.h
 *  @abstract Group
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

#import "EMGroupOptions.h"

/*!
 *  Group
 */
@interface EMGroup : NSObject

/*!
 *  Group id
 */
@property (nonatomic, copy, readonly) NSString *groupId;

/*!
 *  Group's subject, need to fetch group's specification
 */
@property (nonatomic, copy, readonly) NSString *subject;

/*!
 *  Group's description, need to fetch group's specification
 */
@property (nonatomic, copy, readonly) NSString *description;

/*!
 *  The number of members, need to fetch group's specification
 */
@property (nonatomic, readonly) NSInteger occupantsCount;

/*!
 *  Group's setting options, need to fetch group's specification
 */
@property (nonatomic, strong, readonly) EMGroupOptions *setting;

/*!
 *  Group‘s owner, has the highest authority, need to fetch group's specification
 *
 *  A group only has one owner
 */
@property (nonatomic, copy, readonly) NSString *owner;

/*!
 *  Member list of group, need to fetch group's specification
 */
@property (nonatomic, copy, readonly) NSArray *members;

/*!
 *  Group‘s blacklist, need to call fetching group's blacklist method first
 *
 *  Need owner's authority, will return nil if user is not the owner of the group
 */
@property (nonatomic, strong, readonly) NSArray *bans;

/*!
 *  All occupants of the group, include both the owner and all members
 */
@property (nonatomic, strong, readonly) NSArray *occupants;

/*!
 *  Whether this group receive push notifications
 */
@property (nonatomic, readonly) BOOL isPushNotificationEnabled;

/*!
 *  Whether is public group, need to fetch group's specification
 */
@property (nonatomic, readonly) BOOL isPublic;

/*!
 *  Whether block this group‘s message
 */
@property (nonatomic, readonly) BOOL isBlocked;

/*!
 *  Initialize group instance
 *
 *  Please use [+groupWithId:]
 *
 *  @result nil
 */
- (instancetype)init __deprecated_msg("Use +groupWithId:");

/*!
 *  Get group instance, create a instance if do not exist
 *
 *  @param aGroupId    Group id
 *
 *  @result Group instance
 */
+ (instancetype)groupWithId:(NSString *)aGroupId;

@end
