#include "Bureaucrat.hpp"
#include "Form.hpp"

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Bureaucrat grade is TOO HIGH");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Bureaycrat grade is TOO LOW");
}

Bureaucrat::Bureaucrat(std::string const &name, int const &grade) : name_(name), grade_(grade)
{
	if (this->grade_ > 150)
		throw GradeTooLowException();
	if (this->grade_ < 1)
		throw GradeTooHighException();
}

Bureaucrat::~Bureaucrat()
{
}

int	Bureaucrat::getGrade() const
{
	return (this->grade_);
}

std::string	Bureaucrat::getName() const
{
	return (this->name_);
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &obj)
{
	if (this != &obj)
	{
		*(const_cast<std::string*>(&this->name_)) = obj.getName();
		this->grade_ = obj.getGrade();
	}
	return (*this);
}

Bureaucrat::Bureaucrat(Bureaucrat const &obj)
{
	*this = obj;
}

void	Bureaucrat::incrementGrade()
{
	if (this->grade_ == 1)
		throw GradeTooHighException();
	this->grade_--;
}

void	Bureaucrat::decrementGrade()
{
	if (this->grade_ == 150)
		throw GradeTooLowException();
	this->grade_++;
}

std::ostream& operator<<(std::ostream& out, Bureaucrat const &obj)
{
	return (out << obj.getName() << ", bureaucrat grade " << obj.getGrade());
}

void	Bureaucrat::signForm(Form &obj)
{
	try
	{
		obj.beSigned(*this);
		std::cout << this->name_ << " signed " << obj.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->name_ << " couldn't sign " << obj.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(Form const &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->name_ << " executed " << form.getType() << ": " <<form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->name_ << " cannot execute " << form.getType() << ": " << form.getName() << " because "<< e.what() << std::endl;
	}
	
}
