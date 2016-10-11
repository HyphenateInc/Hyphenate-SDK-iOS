/*!
 *  @header EMCursorResult.h
 *  @abstract Subsection result
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

/*!
 *  Subsection result
 */
@interface EMCursorResult : NSObject

/*!
 *  Result list<id>
 */
@property (nonatomic, strong) NSArray *list;

/*!
 *  The cursor of next section
 */
@property (nonatomic, copy) NSString *cursor;

/*!
 *  Get result instance
 *
 *  @param aList    Result list<id>
 *  @param aCusror  The cursor of next section
 *
 *  @result An instance of cursor result
 */
+ (instancetype)cursorResultWithList:(NSArray *)aList
                           andCursor:(NSString *)aCusror;

@end
