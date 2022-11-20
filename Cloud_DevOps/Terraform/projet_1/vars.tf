variable "instance_type" {

    default = "t2.micro"
    type = string
    description = "instance type for my ec2"

}

variable "tag_name" {

    type = string
    description = "tags name for ec2"

}