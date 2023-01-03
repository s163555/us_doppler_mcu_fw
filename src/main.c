#include <kernel.h>
#include <zephyr/kernel_version.h>

uint32_t ver = {0};
uint8_t v_major, v_minor, v_patch = {0};

void version_parse(){
    uint32_t ver = sys_kernel_version_get();
    v_major = (((ver) >> 24) & 0xFF);
    v_minor = (((ver) >> 16) & 0xFF);
    v_patch = (((ver) >> 8) & 0xFF);
}

void main(void)
{
    version_parse();
    printk("hello world\r\n zephyr v %x.%x.%x",v_major,v_minor,v_patch);
}