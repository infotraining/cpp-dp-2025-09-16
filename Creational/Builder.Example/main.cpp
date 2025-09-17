#include "report_builder.hpp"
#include "data_parser.hpp"
#include "person_builder.hpp"
#include <fstream>
#include <iostream>

using namespace std;

constexpr auto file_name = "data_builder.txt";

HtmlDocument build_html_document()
{
    HtmlReportBuilder html_builder;

    DataParser parser(html_builder);
    parser.Parse(file_name);

    return html_builder.get_report();
}

CsvDocument build_csv_document()
{
    CsvReportBuilder csv_builder;

    DataParser parser(csv_builder);
    parser.Parse(file_name);

    return csv_builder.get_report();
}

void person_builder_demo()
{
    Person p = Person::create("Jan", "Kowalski")
        .lives()
            .at("Nigdzie")
            .in("Nibylandia")
            .with_postal_code("00-110")
        .works()
            .in_company("Zeiss")
            .with_tax_id("PL534714576");
}

int main()
{
    HtmlDocument doc_html = build_html_document();

    cout << doc_html << endl;

    cout << "///////////////////////////////////////////////////////////\n";

    CsvDocument csv_doc = build_csv_document();

    for (const auto& line : csv_doc)
        cout << line << endl;

    cout << "///////////////////////////////////////////////////////////\n";

    HtmlReportBuilder html_bld;

    html_bld
        .add_header("TITLE")
        .begin_data()
            .add_row({"one", "two", "three"})
            .add_row({"four", "five", "six"})
        .end_data()
        .add_footer("THE END");

    std::cout << html_bld.get_report() << "\n";

}
