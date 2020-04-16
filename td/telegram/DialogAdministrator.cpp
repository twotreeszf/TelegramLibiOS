//
// Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com) 2014-2020
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#include "td/telegram/DialogAdministrator.h"

#include "td/telegram/ContactsManager.h"

namespace td {

td_api::object_ptr<td_api::chatAdministrator> DialogAdministrator::get_chat_administrator_object(
    const ContactsManager *contacts_manager) const {
  CHECK(contacts_manager != nullptr);
  CHECK(user_id_.is_valid());
  return td_api::make_object<td_api::chatAdministrator>(
      contacts_manager->get_user_id_object(user_id_, "get_chat_administrator_object"), rank_, is_creator_);
}

StringBuilder &operator<<(StringBuilder &string_builder, const DialogAdministrator &administrator) {
  return string_builder << "DialogAdministrator[" << administrator.user_id_ << ", title = " << administrator.rank_
                        << ", is_owner = " << administrator.is_creator_ << "]";
}

}  // namespace td
