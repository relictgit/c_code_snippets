#include <stdio.h>
#include <sys/statvfs.h>

int main(int argc, const char *argv[]) {
  if (argc != 2) {
    printf("=====================================\n");
    printf("argc: %d\n", argc);
    printf("Problem: there is some arguments"
           "missing or too much are being used\n");
    printf("Usage: %s <directory_or_file>\n", argv[0]);
    printf("=====================================\n");
    return 1;
  }
  const unsigned int GB = (1024 * 1024) * 1024;
  struct statvfs disk_buffer;
  const char *path = argv[1];
  /* char path[50] = "";
  printf("This program will have a simmilar output"
         " like you know from the df command\n");
  printf("Provide path for space utilization: ");
  if (scanf("%s", path) == 1) {
    printf("Working on path: %s\n", path);
  } else {
    printf("Failed to read the string\n");
  } */

  int ret = statvfs(path, &disk_buffer);
  if (!ret) {
    const double total =
        (double)(disk_buffer.f_blocks * disk_buffer.f_frsize) / GB;
    const double available =
        (double)(disk_buffer.f_bfree * disk_buffer.f_frsize) / GB;
    const double used = total - available;
    const double used_percentage = (double)(used / total) * (double)100;
    printf("Total: %.3f GB --> %.0f GB \n", total, total);
    printf("Available: %.3f GB --> %.0f GB\n", available, available);
    printf("Used: %.3f GB --> %.0f GB\n", used, used);
    printf("Used percentage: %.2f %% --> %.0f %%\n", used_percentage,
           used_percentage);
    printf("===================================\n");
    printf("structure parameters to the library sys/statvfs\n");
    printf("f_bfree: %lu\n"
           "f_frsize: %lu\nf_blocks: %lu\n"
           "f_flag: %lu\nf_fsid: %lu\n"
           "f_bsize: %lu\nf_ffree: %lu\nf_files: %lu\n"
           "f_bavail: %lu\nf_favail: %lu\nf_namemax: %lu\n",
           disk_buffer.f_bfree, disk_buffer.f_frsize, disk_buffer.f_blocks,
           disk_buffer.f_flag, disk_buffer.f_fsid, disk_buffer.f_bsize,
           disk_buffer.f_ffree, disk_buffer.f_files, disk_buffer.f_bavail,
           disk_buffer.f_favail, disk_buffer.f_namemax);
    printf("===================================\n");
  } else {
    perror("Unable to utilize disk space!\nStopping process\n");
    return 1;
  }
  return ret;
}
