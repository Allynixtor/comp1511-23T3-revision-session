// A program that constructs a list of YouTube videos from input.
// TODO: It then prints the YouTuber from among those videos with the greatest
// likes-to-video ratio.
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 128
struct video {
    char creator[BUFFER_SIZE];
    int likes;
    struct video *next;
};
// provided functions
struct video *populate_video_list_from_input(void);
struct video *create_video(char *creator, int likes);
void print_all_videos(struct video *head);
int main() {
    /* Read input from STDIN. */
    struct video *head_video = populate_video_list_from_input();
    // print_all_videos(head_video);
    
    /* Enter your code here. Print output to STDOUT. */
    
    return 0;
}
// provided functions
struct video *populate_video_list_from_input(void) {
    struct video *head_video = NULL;
    struct video *current_video = NULL;
    
    char input_line[BUFFER_SIZE];
    while (fgets(input_line, BUFFER_SIZE, stdin) != NULL) {
        char creator[BUFFER_SIZE];
        int likes;
        sscanf(input_line, "%[^,],%d", creator, &likes);
        
        if (head_video == NULL) {
            head_video = create_video(creator, likes);
            current_video = head_video;
        } else {
            current_video->next = create_video(creator, likes);
            current_video = current_video->next;
        }
    }
    
    return head_video;
}
struct video *create_video(char *creator, int likes) {
    struct video *new_video = malloc(sizeof(struct video));
    strcpy(new_video->creator, creator);
    new_video->likes = likes;
    new_video->next = NULL;
    return new_video;
}
void print_all_videos(struct video *head) {
    int i = 0;
    struct video *current = head;
    while (current != NULL) {
        printf(
            "video_%d = {\n"
            "    creator: \"%s\",\n"
            "    likes: %d\n"
            "}",
            i,
            current->creator,
            current->likes
        );
        if (current->next != NULL) {
            printf(",");
        }
        printf("\n");
        i++;
        current = current->next;
    }
}
